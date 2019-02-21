#pragma once

#include "Shader.h"

BEGIN(Engine)


class ENGINE_DLL ShaderNormal : public Shader
{
public:
	CREATE(Engine::ShaderNormal)
	CLONE(ShaderNormal)
private:
	explicit ShaderNormal();
public:
	virtual ~ShaderNormal();

public:
	virtual HRESULT	Init();
};


END

