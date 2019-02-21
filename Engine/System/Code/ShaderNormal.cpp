#include "stdafx.h"
#include "ShaderNormal.h"

BEGIN(Engine)


ShaderNormal::ShaderNormal()
{

}

ShaderNormal::~ShaderNormal()
{

}

HRESULT ShaderNormal::Init()
{
	Shader::Init();
	Shader::SetShader
	(
		L"./bin/Resource/HLSL/Shader_Normal.hlsl"
		, L"./bin/Resource/HLSL/Shader_Normal.hlsl"
		, SHARDER_INPUT_ELEMENT_NORMAL
	);


	return S_OK;
}


END