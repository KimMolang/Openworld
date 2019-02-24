#include "stdafx.h"
#include "VIBufferPlane.h"

BEGIN(Engine)


VIBufferPlane::VIBufferPlane()
{

}

VIBufferPlane::~VIBufferPlane()
{
	
}

HRESULT VIBufferPlane::Init()
{
	VIBuffer::Init();

	m_nVtxNum = 4;
	m_nVtxStride = sizeof(VertexTexture);
	m_nVtxOffset = 0;
	m_nVtxStart = 1;

	m_nIdxNum = 6;
	m_nIdxStart = 0;
	m_nIdxPlus = 0;

	Init_Vtx();
	Init_Idx();

	VIBuffer::CreateRasterizerState();


	return S_OK;
}

void VIBufferPlane::Init_Vtx()
{
	VertexTexture pVertex[] =
	{
		{ D3DXVECTOR3(-1.f, 1.f, -1.f)
		, D3DXVECTOR3(0.f, 1.f, 0.f)
		, D3DXVECTOR2(0.f, 0.f) },

		{ D3DXVECTOR3(1.f, 1.f, -1.f)
		, D3DXVECTOR3(0.f, 1.f, 0.f)
		, D3DXVECTOR2(1.f, 0.f) },

		{ D3DXVECTOR3(1.f, -1.f, -1.f)
		, D3DXVECTOR3(0.f, 1.f, 0.f)
		, D3DXVECTOR2(1.f, 1.f) },

		{ D3DXVECTOR3(-1.f, -1.f, -1.f)
		, D3DXVECTOR3(0.f, 1.f, 0.f)
		, D3DXVECTOR2(0.f, 1.f) },
	};


	D3D11_BUFFER_DESC tBufferDesc;
	ZeroMemory(&tBufferDesc, sizeof(D3D11_BUFFER_DESC));
	tBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	tBufferDesc.ByteWidth = m_nVtxStride * m_nVtxNum;
	tBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	tBufferDesc.CPUAccessFlags = 0;
	tBufferDesc.StructureByteStride = 0;

	D3D11_SUBRESOURCE_DATA tData;
	ZeroMemory(&tData, sizeof(D3D11_SUBRESOURCE_DATA));
	tData.pSysMem = pVertex;
	CHECK_FAILED_RETURN(
		GraphicDevice::GetInstance()->GetDevice()->CreateBuffer(&tBufferDesc, &tData, &m_pVtxBuffer), );
}

void VIBufferPlane::Init_Idx()
{
	Index16 pIdx[] =
	{
		{ Index16(0, 1, 2) },
		{ Index16(0, 2, 3) }
	};


	D3D11_BUFFER_DESC tBufferDesc;
	ZeroMemory(&tBufferDesc, sizeof(D3D11_BUFFER_DESC));
	tBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	tBufferDesc.ByteWidth = sizeof(WORD) * m_nIdxNum;
	tBufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
	tBufferDesc.CPUAccessFlags = 0;

	D3D11_SUBRESOURCE_DATA tData;
	ZeroMemory(&tData, sizeof(D3D11_SUBRESOURCE_DATA));
	tData.pSysMem = pIdx;
	CHECK_FAILED_RETURN(
		GraphicDevice::GetInstance()->GetDevice()->CreateBuffer(&tBufferDesc, &tData, &m_pIdxBuffer), );
}


END