#pragma once

#include "Camera.h"

BEGIN(Engine)


// (����) CameraNull �̰� ����� �ߴ�
// ��ġ�� �ڵ尡 ������ ���ɼ��� ������
// ���� ������� ���ô�.
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