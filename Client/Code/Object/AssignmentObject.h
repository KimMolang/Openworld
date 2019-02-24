#pragma once

#include "Object.h"

// (Assignment)
class AssignmentObject : public Engine::GameObject
{
public :
	CREATE(AssignmentObject)
protected:
	explicit AssignmentObject();
public:
	virtual ~AssignmentObject();

public:
	virtual HRESULT					Init();
	virtual Engine::Object::EState	Update();
	virtual void					Render();
	virtual void					Release();
};
