#pragma once

#include "Component.h"

BEGIN(Engine)


class ENGINE_DLL ComponentNull : public Component
{
protected:
	explicit ComponentNull(void) = default;
public:
	virtual ~ComponentNull(void) = default;

public:
	virtual HRESULT	Init() { return S_OK; }
	virtual void Update(void) {};
	virtual void Render(void) {};
	virtual void Release(void) {};


friend ResourceMgr; // ResourceMgr 에서만 생성 가능합니다.
};


END