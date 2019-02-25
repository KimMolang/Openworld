#include "stdafx.h"
#include "AssignmentObject.h"

#include "Export_Function_Mgr.h"


AssignmentObject::AssignmentObject()
{
}

AssignmentObject::~AssignmentObject()
{

}

HRESULT AssignmentObject::Init()
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

Engine::Object::EState AssignmentObject::Update()
{
	const float speed = 25;
	float fTime = Engine::GetTimer()->GetTime();

	bool isMoving = false;

	D3DXVECTOR3 vPos = m_pTransform->GetPos();
	D3DXVECTOR3 vRadian = m_pTransform->GetRadian();

	D3DXMATRIX matWorld = m_pTransform->GetWorldMatrix();
	D3DXVECTOR3 vRight = m_pTransform->GetRightVector();
	D3DXVECTOR3 vDir = m_pTransform->GetDir();

	if (Engine::GetKeyChecker()->CheckKeyboardPress(DIK_A))
	{
		//vPos.x -= speed * fTime;
		vPos -= vRight * speed * fTime;
		isMoving |= true;
	}

	if (Engine::GetKeyChecker()->CheckKeyboardPress(DIK_D))
	{
		//vPos.x += speed * fTime;
		vPos += vRight * speed * fTime;
		isMoving |= true;
	}

	if (Engine::GetKeyChecker()->CheckKeyboardPress(DIK_W))
	{
		//vPos.y += speed * fTime;
		vPos += vDir * speed * fTime;
		isMoving |= true;
	}

	if (Engine::GetKeyChecker()->CheckKeyboardPress(DIK_S))
	{
		//vPos.y -= speed * fTime;
		vPos -= vDir * speed * fTime;
		isMoving |= true;
	}

	if (Engine::GetKeyChecker()->CheckKeyboardPress(DIK_Q))
	{
		vRadian.x += speed * (fTime/3.0f);
		isMoving |= true;
	}

	if (Engine::GetKeyChecker()->CheckKeyboardPress(DIK_E))
	{
		vRadian.y -= speed * (fTime / 3.0f);
		isMoving |= true;
	}

	if (isMoving)
	{
		m_pTransform->SetWorldMatrix(vPos, vRadian);
	}

	return Engine::GameObject::Update();
}

void AssignmentObject::Render()
{
	GameObject::Render();
}

void AssignmentObject::Release()
{
	Engine::Object::Release();
}
