#include "stdafx.h"
#include "Material.h"

BEGIN(Engine)


Material::Material()
{

}

Material::~Material()
{
	Release();
}

HRESULT Material::Init()
{
	return S_OK;
}

void Material::Render()
{
	m_pTexture->Render();
	m_pShader->Render();
}

void Material::Release()
{
	Resource::Release();
}


END