#pragma once

#include "Object.h"

BEGIN(Engine)
// 카메라 변환 행렬 = 카메라 월드 좌표의 역행렬
// 카메라 월드 좌표 * 카메라 월드 좌표의 역행렬 = 단위 행렬
// 여기서 단위 행렬이란 카메라가 아래의 내용과 함께 정중앙에 있다는 의미
// 1 0 0 0 right	는 x 방향으로 길이 1 만큼
// 0 1 0 0 up		는 y 방향으로 길이 1 만큼
// 0 0 1 0 look		는 z 방향으로 길이 1 만큼
// x y z w			를 의미하는 월드행렬
//
// 그래서 카메라의 월드 행렬의 역행렬을 구해서 각 오브젝트의 월드행렬과 곱하면
// 카메라 중심으로 모두 변환된다. (카메라 변환)

class ENGINE_DLL Camera abstract : public Object
{
protected:
	explicit Camera();
public:
	virtual ~Camera()	PURE;

public:
	inline virtual void SetWorldMatrix
	(
		const D3DXVECTOR3& _vPos = D3DXVECTOR3(0.0f, 0.0f, 0.0f)
		, const D3DXVECTOR3& _vRadian = D3DXVECTOR3(0.0f, 0.0f, 0.0f)
		, const D3DXVECTOR3& _vScale = D3DXVECTOR3(1.0f, 1.0f, 1.0f)
	);

private:
	void	Init_Viewport();
	void	Init_ViewBuffer();
	void	Init_ProjBuffer();

protected :
	virtual HRESULT	Init();

public:
	virtual void	Invalidate_View();
	virtual void	Invalidate_Proj();
	virtual void	Invalidate_Ortho();

protected:
	D3DXMATRIX			m_matView;
	D3DXVECTOR3			m_vEye, m_vAt;
	static const D3DXVECTOR3	m_vUp;

	D3DXMATRIX			m_matProj;
	float				m_fFovy, m_fAspect, m_fNear, m_fFar;

	D3D11_VIEWPORT		m_tViewport;

	ID3D11Buffer*		m_pViewBuffer;
	ID3D11Buffer*		m_pProjBuffer;

protected:
	D3DXMATRIX			m_matOrtho;
};


END