#pragma once

#include "Shader.h"

BEGIN(Engine)


class ENGINE_DLL ShaderColor : public Shader
{
public:
	CREATE(Engine::ShaderColor)
	CLONE(ShaderColor)
private:
	explicit ShaderColor();
public:
	virtual ~ShaderColor();

public:
	virtual HRESULT			Init();
};


END

