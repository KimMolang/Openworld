#pragma once

#include "Object.h"

namespace Engine
{
	class Component;
}

class TestTerrain : public Engine::GameObject
{
public:
	explicit TestTerrain();
	virtual ~TestTerrain();

public:
	virtual HRESULT					Init();
	virtual Engine::Object::EState	Update();
	virtual void					Render();
	virtual void					Release();
};
