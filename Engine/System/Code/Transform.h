#pragma once

#include "Component.h"

BEGIN(Engine)


class ENGINE_DLL Transform : public Component
{
public:
	enum class TransformType { STATIC, DYNAMIC };

public :
	CREATE(Engine::Transform)

private:
	explicit Transform();
public:
	virtual ~Transform();

public:
	virtual HRESULT			Init();
	virtual void			Update();
	virtual void			Render();
private:
	virtual void			Release();


private:
	void Init_WorldBuffer();

public:
	GET_USING_REFERENCE(D3DXVECTOR3, Pos, m_vPos);
	GET_USING_REFERENCE(D3DXVECTOR3, Dir, m_vDir);
	GET_USING_REFERENCE(D3DXVECTOR3, Radian, m_vRadian);
	GET_USING_REFERENCE(D3DXVECTOR3, Scale, m_vScale);
	GET_USING_REFERENCE(D3DXMATRIX, WorldMatrix, m_matWorld);

	void SetPos(const D3DXVECTOR3& _vPos);
	void SetWorldMatrix
	(
		const D3DXVECTOR3& _vPos
		, const D3DXVECTOR3& _vRadian
		, const D3DXVECTOR3& _vScale = D3DXVECTOR3(1.0f, 1.0f, 1.0f)
	);
	void Update_WorldMatrix();


public:
	class GraphicDevice*	m_pGraphicDevice;

	ID3D11Buffer*	m_pWorldBuffer;
	TransformType	m_eType;

private:
	D3DXVECTOR3		m_vPos;
	D3DXVECTOR3		m_vRadian;
	D3DXVECTOR3		m_vDir;
	D3DXVECTOR3		m_vScale;

	D3DXMATRIX		m_matWorld;

	// (수정) Physics 컴포넌트 따로 만들기
	//public :
	//	float			m_fSpeed;
	//	float			m_fAccel;
	//	float			m_fWeight;

	//float			m_fAcctime;

	//float			m_fBoosterTimer;
};


END