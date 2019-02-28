#pragma once

#include "VIBuffer.h"

BEGIN(Engine)


class ENGINE_DLL VIBufferCube : public VIBuffer
{
public:
	CREATE(Engine::VIBufferCube);
	CLONE(VIBufferCube);
private:
	explicit VIBufferCube();
public:
	virtual ~VIBufferCube();


public:
	virtual HRESULT			Init();


private:
	void			Init_Vtx();
	void			Init_Idx();
};


END
