#include "stdafx.h"
#include "TestTerrain.h"

#include "Export_Function_Mgr.h"


TestTerrain::TestTerrain()
{
}

TestTerrain::~TestTerrain()
{

}

HRESULT TestTerrain::Init()
{
	Engine::GameObject::Init();


	// Texture ------------
	Engine::Component* pTexture = Engine::GetResourceMgr()->CloneResource(
		Engine::ResourceMgr::RESOURCE_ATTRI_STATIC, Engine::ResourceMgr::RESOURCE_TYPE_TEXTURE, L"Test_Texture_Terrain");
	CHECK_NULLPTR_RETURN(pTexture, E_FAIL);

	// Shader ---------------------
	Engine::Component* pShader = Engine::GetResourceMgr()->CloneResource(
		Engine::ResourceMgr::RESOURCE_ATTRI_STATIC, Engine::ResourceMgr::RESOURCE_TYPE_SHADER, L"Test_Shader_Normal");
	CHECK_NULLPTR_RETURN(pShader, E_FAIL);

	static_cast<Engine::Material*>(m_pMaterial)->SetMaterial(pTexture, pShader);

	// Model Buffer ---------------------
	m_pMeshBuffer = Engine::GetResourceMgr()->CloneResource(
		Engine::ResourceMgr::RESOURCE_ATTRI_STATIC, Engine::ResourceMgr::RESOURCE_TYPE_BUFFER, L"Test_Buffer_Terrain");
	CHECK_NULLPTR_RETURN(m_pMeshBuffer, E_FAIL);


	return S_OK;
}

Engine::Object::EState TestTerrain::Update()
{
	Engine::GameObject::Update();

	return m_eObjState;
}

void TestTerrain::Render()
{
	GameObject::Render();
}

void TestTerrain::Release()
{
	Engine::GameObject::Release();
}
