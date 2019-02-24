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
	, Engine::Component* _pTextrue
)
{
	Component* pComponentNull = ResourceMgr::GetInstance()->GetComponentNull();

	if (_pShader == nullptr)
		m_pShader = pComponentNull;
	else
		m_pShader = _pShader;

	if (_pShader == nullptr)
		m_pTexture = pComponentNull;
	else
		m_pTexture = _pTextrue;
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