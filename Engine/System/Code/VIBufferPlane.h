#pragma once

#include "VIBuffer.h"

BEGIN(Engine)


class ENGINE_DLL VIBufferPlane : public VIBuffer
{
public:
	CREATE(Engine::VIBufferPlane)
	CLONE(VIBufferPlane)
private:
	explicit VIBufferPlane();
public:
	virtual ~VIBufferPlane();


public:
	virtual HRESULT			Init();
protected:
	virtual void	InitRasterizerState();
protected:
	virtual void			Release();


private:
	void			Init_Vtx();
	void			Init_Idx();
};


END
