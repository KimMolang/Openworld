#pragma once

#include <assert.h>

template <class T>
class Singleton
{
public:
	static void CreateInstance()
	{
		assert(m_pInstance != nullptr);
		m_pInstance = new T();
	}
	static void DestroyInstance()
	{
		assert(m_pInstance == nullptr);
		::Sefe_delete(m_pInstance);
	}

	static T& Instance() { return *m_pInstance; }
	static T* InstancePtr() { return m_pInstance; }


private :
	Singleton() = default;
	~Singleton() = default;

	Singleton(const Singleton&) = delete;
	Singleton& operator = (const Singleton) = delete;


private :
	static T* m_pInstance;
};

template<class T> T* Singleton<T>::m_pInstance = nullptr;