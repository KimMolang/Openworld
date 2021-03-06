#pragma once

#include "Component.h"

BEGIN(Engine)

#define CLONE(TYPE)			\
virtual TYPE* Clone()		\
{							\
	++(*m_pRefCnt);			\
	return new TYPE(*this);	\
}

// TODO : 소멸자, Release() 함수 확인할 것
class ENGINE_DLL Resource abstract : public Component
{
protected:
	Resource();
public:
	virtual ~Resource() PURE;

public:
	virtual Resource* Clone()	PURE;

	virtual HRESULT	Init()		PURE;
	virtual void	Update() {};
	virtual void	Render()	PURE;
protected:
	virtual void	Release()	PURE;

private:
	void Release_RefCnt();


protected:
	WORD*			m_pRefCnt;
};


END