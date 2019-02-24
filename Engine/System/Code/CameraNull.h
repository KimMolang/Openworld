#pragma once

#include "Camera.h"

BEGIN(Engine)


// (수정) CameraNull 이걸 쓸라고 했던
// 위치의 코드가 수정될 가능성이 있으니
// 아직 사용하지 맙시다.
class ENGINE_DLL CameraNull : public Camera
{
protected:
	explicit CameraNull() {}
public:
	virtual ~CameraNull() {}

protected:
	virtual HRESULT	Init() {}
	virtual EState	Update() {}
	virtual void	Render() {}
	virtual void	Release() {}

public:
	virtual void	Invalidate_View() {}
	virtual void	Invalidate_Proj() {}
	virtual void	Invalidate_Ortho() {}
};


END