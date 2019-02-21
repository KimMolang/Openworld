#pragma once

#include "Shader.h"

BEGIN(Engine)


class ENGINE_DLL ShaderTerrain : public Shader
{
public:
	CREATE(Engine::ShaderTerrain)
	CLONE(ShaderTerrain)
private:
	explicit ShaderTerrain();
public:
	virtual ~ShaderTerrain();

public:
	virtual HRESULT			Init();
public:
	virtual void	Render();
};


END

