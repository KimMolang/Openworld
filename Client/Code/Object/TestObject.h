#pragma once

#include "Object.h"

namespace Engine
{
	class Component;
}

class TestObject : public Engine::GameObject
{
public:
	explicit TestObject();
	virtual ~TestObject();

public:
	virtual HRESULT					Init();
	virtual Engine::Object::EState	Update();
	virtual void					Render();
	virtual void					Release();
};
