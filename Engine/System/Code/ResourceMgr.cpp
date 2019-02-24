#include "stdafx.h"
#include "ResourceMgr.h"

#include "ShaderColor.h"
//#include "TextureShader.h"
//#include "SkyBoxShader.h"
//#include "AniShader.h"
//
#include "VIBufferCube.h"
//#include "PlanBuffer.h"
//#include "SkyBoxBuffer.h"
//#include "UIBuffer.h"
//
//#include "StaticModel.h"
//#include "DynamicModel.h"
//
//#include "Texture.h"
//#include "Font.h"

#include "ComponentNull.h"

BEGIN(Engine)


IMPLEMENT_SINGLETON_INIT_AND_RELEASE(ResourceMgr)


ResourceMgr::ResourceMgr()
	: m_pComponentNull(nullptr)
{

}

ResourceMgr::~ResourceMgr()
{
	Release_AllResource();
	Release_ComponentNull();
}

HRESULT ResourceMgr::AddResource
(
	const EResourceAttribute& _eResourceAtrri
	, const EResourceType& _eEResourceType
	, const std::wstring& _wstrKey
	, Resource* _pResource
)
{
	std::map<std::wstring, Resource*>::iterator iter
		= m_mapResource[_eResourceAtrri][_eEResourceType].find(_wstrKey);

	if (iter != m_mapResource[_eResourceAtrri][_eEResourceType].end())
		return E_FAIL;

	CHECK_NULLPTR_RETURN(_pResource, E_FAIL);


	m_mapResource[_eResourceAtrri][_eEResourceType].insert(make_pair(_wstrKey, _pResource));
	return S_OK;
}

Resource* ResourceMgr::FindResource
(
	const EResourceAttribute& _eResourceAtrri
	, const EResourceType& _eResourceType
	, const std::wstring& _wstrKey
)
{
	std::map<std::wstring, Resource*>::iterator iter
		= m_mapResource[_eResourceAtrri][_eResourceType].find(_wstrKey);

	if (iter == m_mapResource[_eResourceAtrri][_eResourceType].end())
	{
		MSG_BOX_TAG(_wstrKey.c_str(), L"���ҽ� ������ �������� �ʽ��ϴ�.");
		return NULL;
	}

	return iter->second;
}

Resource* ResourceMgr::CloneResource
(
	const EResourceAttribute& _eResourceAtrri
	, const EResourceType& _eResourceType
	, const std::wstring& _wstrKey
)
{
	std::map<std::wstring, Resource*>::iterator iter
		= m_mapResource[_eResourceAtrri][_eResourceType].find(_wstrKey);

	if (iter == m_mapResource[_eResourceAtrri][_eResourceType].end())
	{
		MSG_BOX_TAG(_wstrKey.c_str(), L"���ҽ� ������ �������� �ʽ��ϴ�.");
		return NULL;
	}

	return iter->second->Clone();
}

void ResourceMgr::Release_DynamicResource()
{
	for (int i = 0; i < RESOURCE_TYPE_END; ++i)
	{
		for_each(m_mapResource[RESOURCE_ATTRI_DYNAMIC][i].begin(),
			m_mapResource[RESOURCE_ATTRI_DYNAMIC][i].end(), ::Safe_Delete_map());
		m_mapResource[RESOURCE_ATTRI_DYNAMIC][i].clear();
	}
}

void ResourceMgr::Release_AllResource()
{
	for (int i = 0; i < RESOURCE_ATTRI_END; ++i)
	{
		for (int j = 0; j < RESOURCE_TYPE_END; ++j)
		{
			for_each(m_mapResource[i][j].begin(),
				m_mapResource[i][j].end(), ::Safe_Delete_map());
			m_mapResource[i][j].clear();
		}
	}
}

HRESULT ResourceMgr::Init()
{
	Init_ComponenetNull();

	return S_OK;
}

void ResourceMgr::Release()
{
	Release_ComponentNull();
}

void ResourceMgr::Init_ComponenetNull()
{
	m_pComponentNull = new ComponentNull();
}

void ResourceMgr::Release_ComponentNull()
{
	::Safe_Delete(m_pComponentNull);
}

END