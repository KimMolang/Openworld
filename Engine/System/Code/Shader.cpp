#include "stdafx.h"
#include "Shader.h"

#include <fstream>

BEGIN(Engine)


Shader::Shader()
	: m_pVertexShader(nullptr)
	, m_pVertexLayout(nullptr)

	, m_pPixelShader(nullptr)
{

}

Shader::~Shader()
{
	Release();
}

HRESULT Shader::SetShader
(
	const LPCWSTR _pathOfVSFile
	, const LPCWSTR _pathOfPSFile
	, const D3D11_INPUT_ELEMENT_DESC _inputElement[] /*= SHARDER_INPUT_ELEMENT_COLOR*/
)
{
	UINT iElementNum = (sizeof(_inputElement) / sizeof(*(_inputElement)));//= ARRAYSIZE(tInputLayout);
	
	if (iElementNum == 0)
		return E_FAIL;


	DWORD swFlag = D3DCOMPILE_ENABLE_STRICTNESS;

#if defined( DEBUG ) || defined( _DEBUG )
	swFlag |= D3D10_SHADER_DEBUG;
#endif

	ID3DBlob* pBlob = nullptr, * pErrorBlob = nullptr;
	ID3D11Device* pDevice = GraphicDevice::GetInstance()->GetDevice();


	if (SUCCEEDED(D3DX11CompileFromFile(_pathOfVSFile, nullptr, nullptr,
		"VS", "vs_5_0", swFlag, 0, nullptr, &pBlob, &pErrorBlob, nullptr)))
	{
		pDevice->CreateVertexShader(pBlob->GetBufferPointer(), pBlob->GetBufferSize(), NULL, &m_pVertexShader);
		pDevice->CreateInputLayout(
			_inputElement, iElementNum, pBlob->GetBufferPointer(), pBlob->GetBufferSize(), &m_pVertexLayout);
	}
	else
	{
		// If the shader failed to compile it should have writen something to the error message.
		if (pErrorBlob)
		{
			OutputShaderErrorMessage(pErrorBlob, "Error_ShaderTerrain_Init_VS.txt");
			CHECK_FAILED_MSG(E_FAIL
				, L"Failed. ErrorMessage is saved as Error_ShaderTerrain::Init::VS.txt");
		}
		else
		{
			CHECK_FAILED_MSG(E_FAIL, L"셰이더 파일이 존재하지 않습니다.");
		}

		return E_FAIL;
	}

	pBlob = pErrorBlob = nullptr;
	if (SUCCEEDED(D3DX11CompileFromFile(_pathOfPSFile, nullptr, nullptr,
		"PS", "ps_5_0", swFlag, 0, nullptr, &pBlob, &pErrorBlob, nullptr)))
	{
		pDevice->CreatePixelShader(pBlob->GetBufferPointer(), pBlob->GetBufferSize(), NULL, &m_pPixelShader);
	}
	else
	{
		if (pErrorBlob)
		{
			OutputShaderErrorMessage(pErrorBlob, "Error_ShaderTerrain_Init_PS.txt");
			CHECK_FAILED_MSG(E_FAIL
				, L"Failed. ErrorMessage is saved as Error_ShaderTerrain::Init::PS.txt");
		}
		else
		{
			CHECK_FAILED_MSG(E_FAIL, L"셰이더 파일이 존재하지 않습니다.");
		}

		return E_FAIL;
	}
	::Safe_Release(pBlob);
	::Safe_Release(pErrorBlob);

	return S_OK;
}

HRESULT Shader::Init()
{
	return S_OK;
}

void Shader::Render()
{
	ID3D11DeviceContext* pDeviceContext = GraphicDevice::GetInstance()->GetDeviceContext();

	if (m_pVertexLayout)
		pDeviceContext->IASetInputLayout(m_pVertexLayout);
	if (m_pVertexShader)
		pDeviceContext->VSSetShader(m_pVertexShader, NULL, 0);
	if (m_pPixelShader)
		pDeviceContext->PSSetShader(m_pPixelShader, NULL, 0);
}

void Shader::Release()
{
	Resource::Release();

	if (m_pRefCnt == nullptr)
	{
		::Safe_Release(m_pVertexShader);
		::Safe_Release(m_pVertexLayout);
		::Safe_Release(m_pPixelShader);
	}
}

void Shader::OutputShaderErrorMessage(ID3D10Blob* _pErrorBlob, char* _fileName)
{
	// Get a pointer to the error message text buffer.
	char* compileErrors = (char*)(_pErrorBlob->GetBufferPointer());
	SIZE_T bufferSize = _pErrorBlob->GetBufferSize();

	std::ofstream fout;
	fout.open(_fileName);

	// Write out the error message.
	for (int i = 0; i<bufferSize; ++i)
	{
		fout << compileErrors[i];
	}

	// Close the file.
	fout.close();
}


END