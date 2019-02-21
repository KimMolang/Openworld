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

	// 템플릿은 컴파일 타임 때 구체화 시켜야하는데 그 때 컴파일 입장에선
	// 저 함수 내부의 타입에 따른 문법 체크를 함
	// 어? 모르는 인스턴스의 Private 함수! 삐빅 호출 못 함!

	// 그래서 여기 말고 Engine::Transform에 위의 함수를 구현하고
	// 사용할 경우 아무 오류 없이 사용 가능. 왜냐하면
	// Transform은 Transform의 private에 접근 가능하니까!!

	// (일반적인 클래스나 함수의 경우 별도의 파일에서 컴파일 과정을 통해서
	// 오브젝트 파일을 만들고 이것을 가지고 링크가 되지만,
	// 함수 템플릿이나 클래스 템플릿은 컴파일 과정에서
	// 해당 문법 체크과정 외에 실제 사용 시 넘겨진 타입 파라미터를
	// 이용해서 구체화(instantiation)과정을 거치게 되는데..)

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