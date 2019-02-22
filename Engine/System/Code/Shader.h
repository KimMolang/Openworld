#pragma once

#include "Resource.h"
#include "GraphicDevice.h"

BEGIN(Engine)

const UINT SHARDER_INPUT_ELEMENT_NUM_COLOR = 2;
const D3D11_INPUT_ELEMENT_DESC SHARDER_INPUT_ELEMENT_COLOR[SHARDER_INPUT_ELEMENT_NUM_COLOR] =
{
		{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 },
		{ "COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 }
};

const UINT SHARDER_INPUT_ELEMENT_NUM_NORMAL = 3;
const D3D11_INPUT_ELEMENT_DESC SHARDER_INPUT_ELEMENT_NORMAL[SHARDER_INPUT_ELEMENT_NUM_NORMAL] =
{
		{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
		{ "NORMAL", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 },
		{ "TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 }
};

class ENGINE_DLL Shader abstract : public Resource
{
protected:
	explicit Shader();
public:
	virtual ~Shader()	PURE;

	HRESULT SetShader
	(
		const LPCWSTR _pathOfVSFile
		, const LPCWSTR _pathOfPSFile
		, const D3D11_INPUT_ELEMENT_DESC _inputElement[] = SHARDER_INPUT_ELEMENT_COLOR
		, const UINT _elementNum = SHARDER_INPUT_ELEMENT_NUM_COLOR
	);

public:
	virtual HRESULT	Init();
	virtual void	Render();
	virtual void	Update() {};
private:
	void			Release();

protected:
	void OutputShaderErrorMessage(ID3D10Blob* _pErrorBlob, char* _fileName);


protected:
	ID3D11VertexShader*		m_pVertexShader;
	ID3D11InputLayout*		m_pVertexLayout;

	ID3D11PixelShader*		m_pPixelShader;
};


END
