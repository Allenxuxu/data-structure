#ifndef STATICSTACK_H
#define STATICSTACK_H

#include "Stack.h"
#include "Exception.h"

namespace XXLib
{

template <typename T,int N>
class StaticStack : public  Stack<T>
{
protected:
    T m_space[N];
    int m_top;
    int m_size;
public:
    StaticStack()
    {
        m_top = -1;
        m_size = 0;
    }

    void push(const T& e)
    {
        if(m_size < N)
        {
            m_space[m_top+1] = e;
            m_size++;
            m_top++;
        }
        else
        {
            THROW_EXCEPTION(InvalidParameterException,"No space in current stack ...");
        }
    }

    void pop()
    {
        if(m_size > 0)
        {
            m_size--;
            m_top--;
        }
        else
        {
            THROW_EXCEPTION(InvalidParameterException,"No element in current stack ...");
        }
    }

    T top() const
    {
        if(m_size > 0)
        {
            return m_space[m_top];
        }
        else
        {
            THROW_EXCEPTION(InvalidParameterException,"No space in current stack ...");
        }
    }

    void clear()
    {
        m_size = 0;
        m_top =-1;
    }
    int size() const
    {
        return m_size;
    }

    int capacity() const
    {
        return N;
    }
};

}
#endif // STATICSTACK_H
