#pragma once

#include "Camera.h"

BEGIN(Engine)


class ENGINE_DLL CameraDynamic : public Camera
{
public:
	CREATE(Engine::CameraDynamic)
private:
	explicit CameraDynamic();
public:
	virtual ~CameraDynamic();


public:
	virtual HRESULT			Init();
	virtual Object::EState	Update();
	virtual void			Render();
	virtual void			Release();


private:
	void	CheckKey();
	void	CheckKey_Move(float _fTime);
	void	CheckKey_Rotate(float _fTime);

	//void	FixMouse();


private:
	float		m_fSpeed;
};


END