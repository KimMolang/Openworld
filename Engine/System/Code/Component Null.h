#pragma once

#include "Component.h"

BEGIN(Engine)


class ENGINE_DLL ComponentNull : public Component
{
protected:
	explicit ComponentNull(void) {};
public:
	virtual ~ComponentNull(void) {};

public:
	virtual HRESULT	Init() { return S_OK; }
	virtual void Update(void) {};
	virtual void Render(void) {};
};


END