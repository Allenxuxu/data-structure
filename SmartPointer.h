#pragma once
#ifndef  SMARTPOINT_H
#define  SMARTPOINT_H

namespace XXLib
{
	template<typename T>
	class SmartPointer
	{
	private:
		T* m_pointer;
	public:
		SmartPointer(T* p=NULL)
		{
			m_pointer = p;
		}
		SmartPointer(const SmartPointer<T>& obj)
		{
			m_pointer = obj.m_pointer;
			const_cast<SmartPointer<T>&>(obj).m_pointer = NULL;
		}
		SmartPointer<T>& operator= (const SmartPointer<T>& obj)
		{
			if (this != &obj)
			{
				delete m_pointer;
				m_pointer = obj.m_pointer;
				const_cast<SmartPointer<T>&>(obj).m_pointer = NULL;
			}
			return *this;
		}
		~SmartPointer()
		{
			delete m_pointer;
		}

		T* operator-> ()
		{
			return m_pointer;
		}
		T& operator* ()
		{
			return *m_pointer;
		}

		bool isNull()
		{
			return (m_pointer == NULL);
		}
		T* get()
		{
			return m_pointer;
		}
	};
}
#endif