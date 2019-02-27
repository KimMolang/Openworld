#include "stdafx.h"
#include "TestObject.h"

#include "Export_Function_Mgr.h"


TestObject::TestObject()
{
}

TestObject::~TestObject()
{
	Release();
}

HRESULT TestObject::Init()
{
	Engine::GameObject::Init();


	// Texture ------------
	// No texture
	// Shader ---------------------
	Engine::Component* pShader = Engine::GetResourceMgr()->CloneResource(
		Engine::ResourceMgr::RESOURCE_ATTRI_STATIC, Engine::ResourceMgr::RESOURCE_TYPE_SHADER, L"Test_Shader_Color");
	CHECK_NULLPTR_RETURN(pShader, E_FAIL);

	static_cast<Engine::Material*>(m_pMaterial)->SetShader(pShader);

	// Model Buffer ---------------------
	m_pMeshBuffer = Engine::GetResourceMgr()->CloneResource(
		Engine::ResourceMgr::RESOURCE_ATTRI_STATIC, Engine::ResourceMgr::RESOURCE_TYPE_BUFFER, L"Test_Buffer_Cube");
	CHECK_NULLPTR_RETURN(m_pMeshBuffer, E_FAIL);


	return S_OK;
}

Engine::Object::EState TestObject::Update()
{
	return Engine::GameObject::Update();
}

void TestObject::Render()
{
	GameObject::Render();
}

void TestObject::Release()
{
	Engine::GameObject::Release();
}
