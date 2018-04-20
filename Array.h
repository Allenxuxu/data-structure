#ifndef ARRAY_H
#define ARRAY_H
#include "Object.h"
#include "Exception.h"
namespace XXLib
{
template <typename T>
class  Array : public Object
{
protected:
    T* m_array;
public:
   virtual  bool set(int i,const T& e)
    {
        bool ret = true;
        if(i>=0 && i < length())
        {
            m_array[i] = e;
        }
        else
        {
            ret = false;
        }
        return ret;
    }
    virtual bool get(int i, T& e)const
    {
        bool ret = true;
        if(i>= 0 && i <length())
        {
            e = m_array[i];
        }
        else
        {
            ret = false;
        }
        return ret;
    }

    T& operator[] (int i)
    {
        if(i>= 0 && i < length())
        {
            return m_array[i];
        }
        else
        {
            THROW_EXCEPTION(IndexOutOfBoundsException,"paramter i is invalid...");
        }
    }

    T operator [] (int i) const
    {
        return const_cast<Array<T>&>(*this)[i];
    }

    virtual int length()const =0;
};
}

#endif // ARRAY_H
