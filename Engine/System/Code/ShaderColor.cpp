#include "stdafx.h"
#include "ShaderColor.h"

#include "GraphicDevice.h"

BEGIN(Engine)


ShaderColor::ShaderColor()
{

}

ShaderColor::~ShaderColor()
{

}

HRESULT ShaderColor::Init()
{
	Shader::Init();
	Shader::SetShader
	(
		L"./bin/Resource/Fx/Shader_Color.fx"
		, L"./bin/Resource/Fx/Shader_Color.fx"
		, SHARDER_INPUT_ELEMENT_COLOR
	);

	return S_OK;
}


END