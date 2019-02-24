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

	// 1) CreateObject(const EObjectID& _eObjectID) ���ϰ� ������
	// ObjectFactory.cpp�� �����ִ� ������Ʈ �� ��Ŭ��� �ؾ��ϰ�
	// 2) emplate<class T> T* CreateObject() ���ϰ� ������
	// �ش� �Լ� ����ϴ� ���� T ���� ��Ŭ��带 �ؾ��մϴ�.
	// 1) ������Ʈ �ϳ��ϳ� ��Ʈ�� ����
	// 2) ������Ʈ �ϳ��ϳ� ��Ʈ�� �Ϸ��� ���ø����� �� ��������
};