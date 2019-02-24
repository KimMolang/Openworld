#include "stdafx.h"
#include "Material.h"

#include "ResourceMgr.h"

BEGIN(Engine)


Material::~Material()
{
	Release();
}

void Material::SetMaterial
(
	Engine::Component* _pShader
	, Engine::Component* _pTextrue /* = nullptr */
)
{
	Component* pComponentNull = ResourceMgr::GetInstance()->GetComponentNull();

	m_pShader = (_pShader == nullptr) ? pComponentNull : _pShader;
	m_pTexture = (_pTextrue == nullptr) ? pComponentNull : _pTextrue;
}

HRESULT Material::Init()
{
	Component* pComponentNull = ResourceMgr::GetInstance()->GetComponentNull();
	m_pTexture = m_pShader = pComponentNull;

	return S_OK;
}

void Material::Render()
{
	m_pTexture->Render();
	m_pShader->Render();
}

void Material::Update()
{

}

void Material::Release()
{
	m_pShader = m_pTexture = nullptr;
}


END