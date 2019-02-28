#pragma once

#include "Resource.h"

BEGIN(Engine)


class ENGINE_DLL Texture : public Resource
{
public :
	enum ETextureType { TEXTURE_TYPE_BASIC, TEXTURE_TYPE_DDS };

public :
	CREATE(Engine::Texture);
	CLONE(Texture)
private:
	Texture() = default;
public:
	virtual ~Texture();


public:
	HRESULT		LoadTexture(std::wstring _wstrPath, const ETextureType& _eTextureType);
private:
	void		LoadTexture_Basic(std::wstring _wstrPath);
	void		LoadTexture_DDS(std::wstring _wstrPath);

public:
	virtual HRESULT			Init();
	virtual void			Render();
private:
	virtual void			Release();


private:
	ID3D11ShaderResourceView*	m_pTextures;
	ID3D11SamplerState*			m_pSamplerStates;
};


END