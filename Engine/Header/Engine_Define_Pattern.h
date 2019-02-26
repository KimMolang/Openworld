#pragma once

#define DEFAULT_CREATER_AND_DESTROYER_FOR_SINGLETONE(CLASSNAME)		\
	private:										\
	CLASSNAME() = delete;							\
	~CLASSNAME() = delete;

#define NO_COPY(CLASSNAME)							\
	private:										\
	CLASSNAME(const CLASSNAME&) = delete;			\
	CLASSNAME& operator = (const CLASSNAME&) = delete;		

#define DECLARE_SINGLETON(CLASSNAME)				\
	NO_COPY(CLASSNAME)								\
	private:										\
	static CLASSNAME*	m_pInstance;				\
	public:											\
	static CLASSNAME*	GetInstance( void );		\
	static void DestroyInstance( void );			

#define IMPLEMENT_SINGLETON(CLASSNAME)				\
	CLASSNAME*	CLASSNAME::m_pInstance = nullptr;	\
	CLASSNAME*	CLASSNAME::GetInstance( void )	{	\
		if(NULL == m_pInstance) {					\
			m_pInstance = new CLASSNAME;			\
		}											\
		return m_pInstance;							\
	}												\
	void CLASSNAME::DestroyInstance( void ) {		\
		if(nullptr != m_pInstance)	{				\
			delete m_pInstance;						\
			m_pInstance = nullptr;					\
		}											\
	}

//#define IMPLEMENT_SINGLETON_INIT_AND_RELEASE(CLASSNAME)	\
//	CLASSNAME*	CLASSNAME::m_pInstance = nullptr;	\
//	CLASSNAME*	CLASSNAME::GetInstance( void )	{	\
//		if(NULL == m_pInstance) {					\
//			m_pInstance = new CLASSNAME;			\
//			m_pInstance->Init();					\
//		}											\
//		return m_pInstance;							\
//	}												\
//	void CLASSNAME::DestroyInstance( void ) {		\
//		if(nullptr != m_pInstance)	{				\
//			m_pInstance->Release();					\
//			delete m_pInstance;						\
//			m_pInstance = nullptr;					\
//		}											\
//	}



#define CREATE(TYPE)		\
static TYPE* Create()		\
{							\
	TYPE* pComponent = new TYPE();	\
									\
	if (FAILED(pComponent->Init()))	\
		::Safe_Delete(pComponent);	\
									\
	return pComponent;		\
}