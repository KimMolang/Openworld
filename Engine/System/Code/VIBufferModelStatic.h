#pragma once

#include "VIBufferModel.h"

BEGIN(Engine)


class VIBufferModelStatic : public VIBufferModel
{
public:
	CREATE(Engine::VIBufferModelStatic);
	CLONE(VIBufferModelStatic);
protected:
	VIBufferModelStatic() = default;
public:
	virtual ~VIBufferModelStatic();

public:
	virtual HRESULT		LoadModel(const char* _path);


public:
	virtual HRESULT		Init();
public:
	virtual void		Update();

private :
	void Release();
};


END