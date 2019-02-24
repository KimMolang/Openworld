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

		OBJECT_ID_MAX,
	};

public :
	class Engine::Object* CreateObject(const EObjectID& _eObjectID);

	template<class T> T* CreateObject()
	{
		T* pTargetCreated = new T();
		pTargetCreated->Init();
		
		return pTargetCreated;
	}
};