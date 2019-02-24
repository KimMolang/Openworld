#pragma once

#include "Object.h"

// (Assignment)
class AssignmentFollowingObject : public Engine::GameObject
{
public :
	CREATE(AssignmentFollowingObject)
protected:
	explicit AssignmentFollowingObject();
public:
	virtual ~AssignmentFollowingObject();

public:
	virtual HRESULT					Init();
	virtual Engine::Object::EState	Update();
	virtual void					Render();
	virtual void					Release();


public :
	Engine::Object* m_pTarget;
};
