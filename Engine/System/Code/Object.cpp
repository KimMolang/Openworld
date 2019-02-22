#include "stdafx.h"
#include "Object.h"

#include <typeinfo>

#include "Component.h"
#include "Transform.h"

BEGIN(Engine)


// 1) Object Class =========================================================================
Object::Object()
{
	
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

template<typename T>
const Component* Object::GetComponent()
{
	for each (auto iter in m_mapComponent)
	{
		//if (typeid(iter->second).Get() == typeid(T).Get())
		if (typeid(iter->second) == typeid(T))
			return iter->second;
	}
}

HRESULT Object::Init()
{
	AddDefaultComponent();

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
	Engine::Object::Render_Component();
}

void Object::Release()
{
	Release_Component();
}

void Object::AddDefaultComponent()
{
	// Transform ------------
	m_pTransform = Transform::Create();
	m_mapComponent.insert(
		std::make_pair(L"Transform", m_pTransform));
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


// 2) GameObject Classs =========================================================================
void GameObject::Render_MaterialAndMesh()
{
	// (수정 1.) 텍스쳐 추가해서 매터리얼로 바꿔랑
	// (수정 2.)
	// (수정 3.) 컴포넌트 널 처리
	// 다 하면 숙제
	// 숙제 다 하면 큐티 끄적이기
	// FBS static 메쉬 읽어 오는 거 구현해놓기
	// 큐티로 맵툴 만들기
	// m_pMaterial
	//m_pMeshBuffer->
}


END