#include "stdafx.h"
#include "Object.h"

#include <typeinfo>

#include "Component.h"
#include "Transform.h"

#include "ResourceMgr.h"

BEGIN(Engine)

// 1) Object =================================
Object::~Object()
{
	Release();
}

void Object::SetWorldMatrix
(
	const D3DXVECTOR3& _vPos /*= D3DXVECTOR3(0.0f, 0.0f, 0.0f)*/
	, const D3DXVECTOR3& _vRadian /*= D3DXVECTOR3(0.0f, 0.0f, 0.0f)*/
	, const D3DXVECTOR3& _vScale /*= D3DXVECTOR3(1.0f, 1.0f, 1.0f)*/
)
{
	if (m_pTransform == nullptr)
		return;

	m_pTransform->SetWorldMatrix(_vPos, _vRadian, _vScale);
}

const Component* Object::GetComponent(const std::wstring& _wstrComponentKey)
{
	MAPCOMPONENT::iterator iter = m_mapComponent.find(_wstrComponentKey);

	if (iter == m_mapComponent.end())
		return nullptr;

	return iter->second;
}

HRESULT Object::Init()
{
	// Transform ------------
	m_pTransform = Transform::Create();
	m_mapComponent.insert(
		std::make_pair(L"Transform", m_pTransform));

	m_eObjState = EState::STATE_ALIVE;


	return S_OK;
}

Object::EState Object::Update()
{
	Engine::Object::Update_Component();

	return m_eObjState;
}

void Object::Render()
{
	m_pTransform->Render();
}

void Object::Release()
{
	Release_Component();
}

void Object::Update_Component()
{
	MAPCOMPONENT::iterator iter = m_mapComponent.begin();
	MAPCOMPONENT::iterator iter_end = m_mapComponent.end();

	for (; iter != iter_end; ++iter)
		iter->second->Update();
}

void Object::Render_Component()
{
	MAPCOMPONENT::iterator iter = m_mapComponent.begin();
	MAPCOMPONENT::iterator iter_end = m_mapComponent.end();

	for (; iter != iter_end; ++iter)
		iter->second->Render();
}

void Object::Release_Component()
{
	for_each(m_mapComponent.begin(), m_mapComponent.end(), Safe_Delete_map());
	m_mapComponent.clear();
}


// 2) GameObject =================================
GameObject::GameObject()
{
	
}

HRESULT GameObject::Init()
{
	Object::Init();


	Component* pComponentNull
		= ResourceMgr::GetInstance()->GetComponentNull();

	// Material ------------
	m_pMaterial = Material::Create();
	m_mapComponent.insert(
		std::make_pair(L"Material", m_pMaterial));

	// Mesh Buffer
	m_pMeshBuffer = pComponentNull;
	m_mapComponent.insert(
		std::make_pair(L"MeshBuffer", m_pMeshBuffer));


	return S_OK;
}

void GameObject::Render()
{
	Object::Render();

	m_pMaterial->Render();
	m_pMeshBuffer->Render();
}

END