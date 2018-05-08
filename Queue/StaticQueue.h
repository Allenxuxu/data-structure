#ifndef STATICQUEUE_H
#define STATICQUEUE_H

#include "Exception.h"

#include "Queue.h"
namespace XXLib
{
template <typename T, int N>
class StaticQueue :public Queue<T>
{
protected:
    T m_space[N];
    int m_font;       //为队列中第一个元素下标
    int m_rear;        //为队列中最后一个元素后面一个元素的下标
    int m_length;
public:
    StaticQueue()
    {
        m_font = 0;
        m_rear = 0;
        m_length = 0;
    }

    int capacity() const
    {
        return N;
    }

    void add(const T &e)
    {
        if(m_length < N)
        {
            m_space[m_rear] = e;
            m_length++;
            m_rear = (m_rear +1) % N;
        }
        else
        {
            THROW_EXCEPTION(InvalidParameterException, "No space in current queue ...");
        }
    }

    void remove()
    {
        if(m_length > 0)
        {
            m_font = (m_font+1) % N;   //循环计数法 来提高队列操作效率
            m_length--;
        }
        else
        {
             THROW_EXCEPTION(InvalidParameterException, "No element in current queue ...");
        }
    }

    T front() const
    {
        if(m_length >0)
        {
            return m_space[m_font];
        }
        else
        {
             THROW_EXCEPTION(InvalidParameterException, "No element  in current queue ...");
        }
    }

    void clear()
    {
        m_length = 0;
        m_font = 0;
        m_rear = 0;
    }

    int length() const
    {
        return m_length;
    }

};


}
#endif // STATICQUEUE_H
