#include "stdafx.h"
#include "AssignmentFollowingObject.h"

#include "Export_Function_Mgr.h"


AssignmentFollowingObject::AssignmentFollowingObject()
{
}

AssignmentFollowingObject::~AssignmentFollowingObject()
{

}

HRESULT AssignmentFollowingObject::Init()
{
	Engine::GameObject::Init();


	// Texture ------------
	// No texture
	// Shader ---------------------
	Engine::Component* pShader = Engine::GetResourceMgr()->CloneResource(
		Engine::ResourceMgr::RESOURCE_ATTRI_STATIC, Engine::ResourceMgr::RESOURCE_TYPE_SHADER, L"Test_Shader_Color");
	CHECK_NULLPTR_RETURN(pShader, E_FAIL);

	static_cast<Engine::Material*>(m_pMaterial)->SetMaterial(pShader);

	// Model Buffer ---------------------
	m_pMeshBuffer = Engine::GetResourceMgr()->CloneResource(
		Engine::ResourceMgr::RESOURCE_ATTRI_STATIC, Engine::ResourceMgr::RESOURCE_TYPE_BUFFER, L"Test_Buffer_Plane");
	CHECK_NULLPTR_RETURN(m_pMeshBuffer, E_FAIL);


	return S_OK;
}

Engine::Object::EState AssignmentFollowingObject::Update()
{
	const float speed = 10;
	float fTime = Engine::GetTimer()->GetTime();

	// (내일)(수정)아니 왜 겟 트랜스폼 안 됨?!
	D3DXVECTOR3 vTargetPos = m_pTarget->m_pTransform->GetPos();
	D3DXVECTOR3 vPos = m_pTransform->GetPos();
	D3DXVECTOR3 vRadian = m_pTransform->GetRadian();

	D3DXVECTOR3 vDir = vTargetPos - vPos;
	D3DXVec3Normalize(&vDir, &vDir);

	vPos += vDir * speed * fTime;

	D3DXVECTOR3 vGapRadian
		= m_pTarget->m_pTransform->GetRadian() - vRadian;

	vRadian += vGapRadian * (speed/3.0f) * fTime;

	//D3DXMATRIX matWorld = m_pTransform->GetWorldMatrix();
	//// (수정) (내일) 함수로 다 만들자
	//D3DXVECTOR3 vRight(matWorld._11, matWorld._12, matWorld._13);
	//D3DXVECTOR3 vDir(matWorld._31, matWorld._32, matWorld._33);



	m_pTransform->SetWorldMatrix(vPos, vRadian);

	return Engine::GameObject::Update();
}

void AssignmentFollowingObject::Render()
{
	GameObject::Render();
}

void AssignmentFollowingObject::Release()
{
	Engine::Object::Release();
}
