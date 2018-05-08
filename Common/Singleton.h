#pragma once
#ifndef _SINGLETON_H_
#define _SINGLETON_H_


namespace XXLib
{
	template< typename T >
	class Singleton
	{
		static T* c_instance;
	public:
		static T* GetInstance();
	};
	template< typename T >
	T* Singleton<T>::c_instance = NULL;
	template< typename T >
	T* Singleton<T>::GetInstance()
	{
		if (c_instance == NULL)
		{
			c_instance = new T();
		}
		return c_instance;
	}
}
#endif