#pragma once

#include "Component.h"
#include "Transform.h"

#include "Material.h"

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
	explicit Object(void) = default;
public:
	virtual ~Object(void) = default;
	// ���� �Լ��� �ܼ��� �������̽� ���⸸�����ϱ� ������ (�̷� �� �ʿ��մϴ�!)
	// ��ü�� �ʿ������
	// �Ҹ��ڿ� ���� Ű���带 ���̸� �� �ǹ̰� �޶�����.
	// �̰� abstract Ŭ�����Դϴ�! ��� �ǹ�.
	// �׷��� ��ü�� �ʿ��մϴ�.

public:
	const Component*	GetComponent(const std::wstring& _wstrComponentKey);
	template<typename T> const Component*	GetComponent()
	{
		for each (auto& iter in m_mapComponent)
		{
			//if (typeid(iter->second).Get() == typeid(T).Get())
			if (typeid(iter->second) == typeid(T))
				return iter->second;
		}
	}

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
	class Transform*	m_pTransform;

	friend class Layer;
};

class ENGINE_DLL GameObject abstract : public Object
{
protected:
	explicit GameObject(void);
public:
	virtual ~GameObject(void) = default;
	// ���� �Լ��� �ܼ��� �������̽� ���⸸�����ϱ� ������ (�̷� �� �ʿ��մϴ�!)
	// ��ü�� �ʿ������
	// �Ҹ��ڿ� ���� Ű���带 ���̸� �� �ǹ̰� �޶�����.
	// �̰� abstract Ŭ�����Դϴ�! ��� �ǹ�.
	// �׷��� ��ü�� �ʿ��մϴ�.


protected:
	class Component*	m_pMaterial;
	class Component*	m_pMeshBuffer;
};


END