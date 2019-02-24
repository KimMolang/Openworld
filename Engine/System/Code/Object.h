#pragma once

#include "Component.h"
#include "Transform.h"

BEGIN(Engine)


class ENGINE_DLL Object abstract
{
public:
	enum class EState
	{
		STATE_NONE,

		STATE_IDLE,
		STATE_ALIVE,
		STATE_DIE
	};

protected:
	explicit Object(void);
public:
	virtual ~Object(void) PURE;

public:
	const Component*	GetComponent(const std::wstring& _wstrComponentKey);
	template<typename T> const Component*	GetComponent();

	GET(Engine::Object::EState, ObjState, m_eObjState);
protected:
	SET(Engine::Object::EState, ObjState, m_eObjState);

public :
	inline void SetWorldMatrix
	(
		const D3DXVECTOR3& _vPos = D3DXVECTOR3(0.0f, 0.0f, 0.0f)
		, const D3DXVECTOR3& _vRadian = D3DXVECTOR3(0.0f, 0.0f, 0.0f)
		, const D3DXVECTOR3& _vScale = D3DXVECTOR3(1.0f, 1.0f, 1.0f)
	);

public :
	virtual HRESULT			Init();
protected:
	virtual Object::EState	Update();
	virtual void			Render();
	virtual void			Release();


private:
	void	AddDefaultComponent();
protected:
	void	Update_Component();
	void	Render_Component();
protected:
	void	Release_Component();


protected:
	typedef std::map<std::wstring, Component*>	MAPCOMPONENT;
	MAPCOMPONENT		m_mapComponent;
	EState				m_eObjState;

protected:
	class Transform*			m_pTransform;

	friend class Layer;
};


class ENGINE_DLL GameObject abstract : public Object
{
protected:
	explicit GameObject(void) {};
public:
	virtual ~GameObject(void) PURE {};

protected:
	virtual void	Render_MaterialAndMesh()
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
	};


protected:
	class Material*	m_pMaterial; // (수정) 텍스쳐 추가해서 매터리얼로 바꿔랑
	class VIBuffer*	m_pMeshBuffer;
};


END