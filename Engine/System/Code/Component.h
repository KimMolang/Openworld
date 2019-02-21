#pragma once

BEGIN(Engine)


class ENGINE_DLL Component abstract
{
public :
	//template<class T> static T* Create()
	//{
	//	T* pComponent = new T();

	//	if (FAILED(pComponent->Init()))
	//		::Safe_Delete(pComponent);

	//	return pComponent;
	//}
	// error C2248: 'Engine::Transform::Transform'
	//	: cannot access private member declared in class 'Engine::Transform'

	// ���ø��� ������ Ÿ�� �� ��üȭ ���Ѿ��ϴµ� �� �� ������ ���忡��
	// �� �Լ� ������ Ÿ�Կ� ���� ���� üũ�� ��
	// ��? �𸣴� �ν��Ͻ��� Private �Լ�! �ߺ� ȣ�� �� ��!

	// �׷��� ���� ���� Engine::Transform�� ���� �Լ��� �����ϰ�
	// ����� ��� �ƹ� ���� ���� ��� ����. �ֳ��ϸ�
	// Transform�� Transform�� private�� ���� �����ϴϱ�!!

	// (�Ϲ����� Ŭ������ �Լ��� ��� ������ ���Ͽ��� ������ ������ ���ؼ�
	// ������Ʈ ������ ����� �̰��� ������ ��ũ�� ������,
	// �Լ� ���ø��̳� Ŭ���� ���ø��� ������ ��������
	// �ش� ���� üũ���� �ܿ� ���� ��� �� �Ѱ��� Ÿ�� �Ķ���͸�
	// �̿��ؼ� ��üȭ(instantiation)������ ��ġ�� �Ǵµ�..)

protected:
	explicit Component(void);
public:
	virtual ~Component(void) PURE;

public:
	virtual HRESULT Init(void) PURE;
	virtual void Update(void) PURE;
	virtual void Render(void) PURE;
};


END