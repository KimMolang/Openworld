#include "stdafx.h"
#include "VIBufferModelStatic.h"

#include <assert.h>
#include "ResourceMgr.h"

BEGIN(Engine)


VIBufferModelStatic::~VIBufferModelStatic()
{
	Release();
}

HRESULT VIBufferModelStatic::Init()
{
	VIBufferModel::InitRasterizerState();

	return S_OK;
}

void VIBufferModelStatic::Update()
{

}

HRESULT VIBufferModelStatic::LoadModel(const char* _path)
{
	FbxManager* pFBXManager = FbxManager::Create();
	FbxIOSettings* pIOsettings = FbxIOSettings::Create(pFBXManager, IOSROOT);
	pFBXManager->SetIOSettings(pIOsettings);
	FbxScene* pFBXScene = FbxScene::Create(pFBXManager, "");

	FbxImporter* pImporter = FbxImporter::Create(pFBXManager, "");


	if (!(pImporter->Initialize(_path, -1, pFBXManager->GetIOSettings())))
		CHECK_FAILED_MSG(E_FAIL, L"Model Init Failed");

	if (!(pImporter->Import(pFBXScene)))
		CHECK_FAILED_MSG(E_FAIL, L"Model Import Failed");


	FbxGeometryConverter clsConverter(pFBXManager);
	clsConverter.Triangulate(pFBXScene, false);
	FbxNode* pRootNode = pFBXScene->GetRootNode();

	if (!pRootNode)
		return E_FAIL;


	std::vector<VertexTexture*> vecVertexTexture;

	for (int i = 0; i < pRootNode->GetChildCount(); ++i)
	{
		FbxNode* pChildNode = pRootNode->GetChild(i);

		if (pChildNode->GetNodeAttribute() == NULL)
			continue;

		FbxNodeAttribute::EType AttributeType
			= pChildNode->GetNodeAttribute()->GetAttributeType();

		if (AttributeType != FbxNodeAttribute::eMesh)
			continue;


		FbxMesh* pMesh = (FbxMesh*)pChildNode->GetNodeAttribute();
		D3DXVECTOR3 m_pos;
		D3DXVECTOR2 outUV;
		D3DXVECTOR3 outNormal;
		FbxVector4* mControlPoints = pMesh->GetControlPoints();
		int vertexCounter = 0;

		for (int j = 0; j < pMesh->GetPolygonCount(); j++)
		{
			int iNumVertices = pMesh->GetPolygonSize(j);
			assert(iNumVertices == 3);
			FbxGeometryElementUV* vertexUV = pMesh->GetElementUV(0);
			FbxGeometryElementNormal* vertexNormal = pMesh->GetElementNormal(0);

			for (int k = 0; k < iNumVertices; k++)
			{
				// 정점데이터 얻어오기
				int iControlPointIndex = pMesh->GetPolygonVertex(j, k);
				int inTextureUVIndex = pMesh->GetTextureUVIndex(j, k);
				++vertexCounter;

				m_pos.x = (float)mControlPoints[iControlPointIndex].mData[0];
				m_pos.y = (float)mControlPoints[iControlPointIndex].mData[1];
				m_pos.z = (float)mControlPoints[iControlPointIndex].mData[2];


				// uv얻기
				switch (vertexUV->GetMappingMode())
				{

				case FbxGeometryElement::eByControlPoint:

					switch (vertexUV->GetReferenceMode())
					{
					case FbxGeometryElement::eDirect:
					{
						outUV.x = static_cast<float>(vertexUV->GetDirectArray()
							.GetAt(iControlPointIndex).mData[0]);
						outUV.y = 1 - static_cast<float>(vertexUV->GetDirectArray()
							.GetAt(iControlPointIndex).mData[1]);
					}
						break;

					case FbxGeometryElement::eIndexToDirect:
					{
						int index = vertexUV->GetIndexArray().GetAt(iControlPointIndex);
						outUV.x = static_cast<float>(vertexUV->GetDirectArray().GetAt(index).mData[0]);
						outUV.y = 1 - static_cast<float>(vertexUV->GetDirectArray().GetAt(index).mData[1]);
					}
						break;

					default:
						throw std::exception("Invalid Reference");
						// (수정) 캐치하기 싫다고
					}
					break;

				case FbxGeometryElement::eByPolygonVertex:
					switch (vertexUV->GetReferenceMode())
					{
					case FbxGeometryElement::eDirect:
					case FbxGeometryElement::eIndexToDirect:
						outUV.x = static_cast<float>(vertexUV->GetDirectArray()
							.GetAt(inTextureUVIndex).mData[0]);
						outUV.y = 1 - static_cast<float>(vertexUV->GetDirectArray()
							.GetAt(inTextureUVIndex).mData[1]);
						break;

					default:
						throw std::exception("Invalid Reference");
						// (수정) 캐치하기 싫다고
					}
					break;

				default:
					throw std::exception("Invalid Reference");
					// (수정) 캐치하기 싫다고
					break;
				}

				VertexTexture*  m_Ver = new VertexTexture(
					D3DXVECTOR3(m_pos.x, m_pos.z, -m_pos.y),
					D3DXVECTOR3(outNormal.x, outNormal.z, -outNormal.y),
					D3DXVECTOR2(outUV.x, outUV.y));
				vecVertexTexture.push_back(m_Ver);
			}
		}
	}

	size_t n = vecVertexTexture.size();
	VertexTexture* pVertexTexture = new VertexTexture[n];
	for (unsigned int i = 0; i < vecVertexTexture.size(); ++i)
	{
		// vecVertexTexture.at(i) 는 catch 문을 사용하지 않기 때문에 지웠습니다 (명지)
		pVertexTexture[i].vPos = vecVertexTexture[i]->vPos;
		pVertexTexture[i].vNormal = vecVertexTexture[i]->vNormal;
		pVertexTexture[i].vTextureUV = vecVertexTexture[i]->vTextureUV;
	}

	m_nVtxNum = static_cast<UINT>(vecVertexTexture.size());
	m_nVtxStride = sizeof(VertexTexture);
	m_nVtxOffset = 0;

	MakeVertexNormal((BYTE*)pVertexTexture, NULL);

	D3D11_BUFFER_DESC tBufferDesc;
	ZeroMemory(&tBufferDesc, sizeof(D3D11_BUFFER_DESC));
	tBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	tBufferDesc.ByteWidth = m_nVtxStride * m_nVtxNum;
	tBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	tBufferDesc.CPUAccessFlags = 0;

	D3D11_SUBRESOURCE_DATA tData;
	ZeroMemory(&tData, sizeof(D3D11_SUBRESOURCE_DATA));
	tData.pSysMem = pVertexTexture;
	GraphicDevice::GetInstance()->GetDevice()->CreateBuffer(&tBufferDesc, &tData, &m_pVtxBuffer);

	pFBXScene->Destroy();
	pImporter->Destroy();
	pIOsettings->Destroy();
	pFBXManager->Destroy();


	return S_OK;
}

void VIBufferModelStatic::Release()
{
	VIBufferModel::Release();

	if ((*m_pRefCnt) == 0)
	{
		::Safe_Release(m_pVtxBuffer);
		::Safe_Release(m_pIdxBuffer);
	}
	else --(*m_pRefCnt);
}

END