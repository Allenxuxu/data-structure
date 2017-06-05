#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H
#include "Array.h"
#include "Exception.h"
namespace XXLib
{
template <typename T>
class DynamicArray :public Array<T>
{
protected:
    int m_length;

    T* copy(T* array, int len, int newlen)
    {
        T* ret = new T[newlen];
        if(ret != NULL)
        {
            int size = (len < newlen) ? len : newlen;

            for(int i=0; i<size; i++)
            {
                ret[i] = array[i];
            }
        }
        return ret;
    }

    void update(T* array, int length)
    {
        if(array != NULL)
        {
            T* temp = this->m_array;

            this->m_array = array;
            this->m_length = length;

            delete [] temp;
        }
        else
        {
                THROW_EXCEPTION(NoEnoughtMemoryException,"No memory to create DynamicArray object....");
        }
    }

    void init(T* array, int length)
    {
        if(array != NULL)
        {
            this->m_array = array;
            this->m_length = length;
        }
        else
        {
            THROW_EXCEPTION(NoEnoughtMemoryException,"No memory to create DynamicArray object....");
        }
    }

public:
    DynamicArray(int length)
    {
        init(new T[length],length);
    }

    DynamicArray(const DynamicArray<T>& obj)
    {
        init(copy(obj.m_array,obj.m_length,obj.m_length),obj.m_length);
    }

    DynamicArray<T>& operator =(const DynamicArray<T>& obj)
    {
        if(this != &obj)
        {
            update(copy(obj.m_array,obj.m_length,obj.m_length),obj.m_length);
        }
        return *this;
    }

    int length() const
    {
        return m_length;
    }

    void resize(int length)
    {
        if(this->m_length != length)
        {
            update(copy(this->m_array,this->m_length,length), length);
        }
    }

    ~DynamicArray()
    {
        delete []this->m_array;
    }

};

}
#endif // DYNAMICARRAY_H
