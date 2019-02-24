#include "stdafx.h"
#include "AssignmentObject.h"

#include "ResourceMgr.h"
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
