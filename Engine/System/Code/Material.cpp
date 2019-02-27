#include "stdafx.h"
#include "Material.h"

#include "ResourceMgr.h"

BEGIN(Engine)


Material::~Material()
{
	Release();
}

void Material::SetShader( Engine::Component* _pShader)
{
	Component* pComponentNull = ResourceMgr::GetInstance()->GetComponentNull();

	m_pShader = (_pShader == nullptr) ? pComponentNull : _pShader;
}

void Material::SetTexture(Engine::Component* _pTexture)
{
	Component* pComponentNull = ResourceMgr::GetInstance()->GetComponentNull();

	m_pTexture = (_pTexture == nullptr) ? pComponentNull : _pTexture;
}

void Material::SetMaterial
(
	Engine::Component* _pShader
	, Engine::Component* _pTexture
)
{
	SetShader(_pShader);
	SetTexture(_pTexture);
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
	Component::Release();

	m_pShader = m_pTexture = nullptr;
}


END