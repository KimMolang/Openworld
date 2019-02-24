#include "stdafx.h"
#include "ObjectFactory.h"

#include "Engine_Define_Check.h"

#include "Object.h"

#include "../Object/TestObject.h"

#include "CameraDynamic.h"
#include "../Object/TestTerrain.h"

IMPLEMENT_SINGLETON(ObjectFactory)


ObjectFactory::ObjectFactory()
{
}


ObjectFactory::~ObjectFactory()
{

}

Engine::Object* ObjectFactory::CreateObject(const EObjectID & _eObjectID)
{
	Engine::Object* pTargetCreated	= nullptr;

	switch (_eObjectID)
	{
	case EObjectID::OBJECT_ID_TEST :
		// (001 수정) Create 매크로 만들어 났음
		pTargetCreated = new TestObject();
		pTargetCreated->Init();
		break;

	case EObjectID::OBJECT_ID_CAMERA_DYNAMIC :
		pTargetCreated = Engine::CameraDynamic::Create();
		break;

	case EObjectID::OBJECT_ID_TERRAIN :
		pTargetCreated = new TestTerrain();
		pTargetCreated->Init();
		break;

	default :
		break;
	}

	return pTargetCreated;
}

