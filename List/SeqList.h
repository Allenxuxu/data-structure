#ifndef SEQLIST_H
#define SEQLIST_H
#include "List.h"
#include "Exception.h"
namespace  XXLib
{
    template <typename T>
    class SeqList : public List<T>
    {
    protected:
        T* m_array;
        int m_length;
    public:
        bool insert(const T& e)
        {
            return insert(m_length,e);
        }

        bool insert(int i, const T& e)
        {
            bool ret = false;
            if ( (i >= 0)  && (i <= m_length)  && (m_length < capacity()))
            {
                for(int p = m_length-1; p >= i; p--)
                {
                    m_array[p+1] = m_array[p];
                }

                m_array[i] = e;
                m_length++;

                ret = true;
            }
            return ret;
        }

        bool remove(int i)
        {
            bool ret = false;
            if ( (i >=0)  && (i<m_length) )
            {
                for(int p=i; p<m_length-1; p++)
                {
                    m_array[i] = m_array[i+1];
                }
                m_length--;

                ret = true;
            }
            return ret;
        }

        bool set(int i, const T& e)
        {
            bool ret = false;
            if ((i >=0)  && (i<m_length))
            {
                m_array[i] = e;
            }
            return ret;
        }

        bool get(int i, T& e)const
        {
            bool ret = false;
            if ((i >=0)  && (i<m_length))
            {
                e = m_array[i];
            }
            return ret;
        }

        T get(int i) const
        {
            T ret;
            if(get(i,ret))
            {
                return ret;
            }
            else
            {
                THROW_EXCEPTION(IndexOutOfBoundsException,"Invalid parameter i to get element ...");
            }
        }

        int length()const
        {
            return m_length;
        }

        void clear()
        {
            m_length = 0;
        }

        int find(const T &e) const
        {
            int ret =-1;

            for(int i=0; i<m_length; i++)
            {
                if( m_array[i] == e)
                {
                    ret =i;
                    break;
                }
            }

            return ret;
        }

        T& operator [] (int i)
        {
            if ((i >=0)  && (i<m_length))
            {
                return m_array[i];
            }
            else
            {
                THROW_EXCEPTION(ArithmeticException,"");
            }
        }

        T operator [](int i)const
        {
            return  const_cast<SeqList<T>&>(*this)[i];
        }

        virtual int capacity()const = 0 ;

    public:
        typedef const T*    const_iterator;
        typedef T*          iterator;

        iterator begin()
        { return m_array; }

        const_iterator begin() const
        { return m_array; }

        iterator end()
        { return m_array + length(); }

        const_iterator end() const
        { return m_array + length(); }
    };
}
#endif // SEQLIST_H
