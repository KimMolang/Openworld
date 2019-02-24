#pragma once

#include "Object.h"

BEGIN(Engine)
// ī�޶� ��ȯ ��� = ī�޶� ���� ��ǥ�� �����
// ī�޶� ���� ��ǥ * ī�޶� ���� ��ǥ�� ����� = ���� ���
// ���⼭ ���� ����̶� ī�޶� �Ʒ��� ����� �Բ� ���߾ӿ� �ִٴ� �ǹ�
// 1 0 0 0 right	�� x �������� ���� 1 ��ŭ
// 0 1 0 0 up		�� y �������� ���� 1 ��ŭ
// 0 0 1 0 look		�� z �������� ���� 1 ��ŭ
// x y z w			�� �ǹ��ϴ� �������
//
// �׷��� ī�޶��� ���� ����� ������� ���ؼ� �� ������Ʈ�� ������İ� ���ϸ�
// ī�޶� �߽����� ��� ��ȯ�ȴ�. (ī�޶� ��ȯ)

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