#pragma once

#include "Resource.h"

#include "Shader.h"
#include "Texture.h"

BEGIN(Engine)

class ENGINE_DLL Material : public Component
{
public :
	CREATE(Engine::Material)
protected:
	explicit Material() = default;
public:
	virtual ~Material();

	void SetMaterial
	(
		Engine::Component* _pShader
		, Engine::Component* _pTextrue
	);

public:
	virtual HRESULT	Init();
	virtual void	Render();
	virtual void	Update();
private:
	void			Release();


private :
	Component* m_pShader;
	Component* m_pTexture;	// (����) �ϴ� �ؽ��� �ϳ��� �ӽ÷� ������ ����.
};


END
