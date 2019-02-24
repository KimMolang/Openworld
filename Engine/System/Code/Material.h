#pragma once

#include "Resource.h"

#include "Shader.h"
#include "Texture.h"

BEGIN(Engine)

class ENGINE_DLL Material abstract : public Resource
{
protected:
	explicit Material() /*= default*/;
public:
	virtual ~Material()	PURE;

	void SetMaterial ( Engine::Component* _pShader, Engine::Component* _pTextrue)
	{
		m_pShader = _pShader;
		m_pTexture = _pTextrue;
	}

public:
	virtual HRESULT	Init();
	virtual void	Render();
	virtual void	Update() {};
private:
	void			Release();


private :
	Component* m_pShader;
	Component* m_pTexture;	// (����) �ϴ� �ؽ��� �ϳ��� �ӽ÷� ������ ����.
};


END
