#pragma once

namespace Engine
{
	class Object;
}

class  ObjectFactory
{
	DECLARE_SINGLETON(ObjectFactory)

private:
	ObjectFactory();
	~ObjectFactory();

public:
	enum class EObjectID
	{
		OBJECT_ID_TEST,
		OBJECT_ID_CAMERA_DYNAMIC,
		OBJECT_ID_TERRAIN,
		OBJECT_ID_ASSIGNMENT, // (Assignment)

		OBJECT_ID_MAX,
	};
	

public :
	class Engine::Object* CreateObject(const EObjectID& _eObjectID); // 1)

	template<class T> T* CreateObject() // 2)
	{
		T* pTargetCreated = new T();
		pTargetCreated->Init();
		
		return pTargetCreated;
	}

	// 1) CreateObject(const EObjectID& _eObjectID) 콜하고 싶으면
	// ObjectFactory.cpp에 관련있는 오브젝트 다 인클루드 해야하고
	// 2) emplate<class T> T* CreateObject() 콜하고 싶으면
	// 해당 함수 사용하는 곳에 T 관련 인클루드를 해야합니다.
	// 1) 오브젝트 하나하나 컨트롤 가능
	// 2) 오브젝트 하나하나 컨트롤 하려면 템플릿으로 더 만들어야함
};