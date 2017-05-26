#ifndef SEQLIST_H
#define SEQLIST_H
#include "List.h"

namespace  XXLib
{
template <typename T>
class SeqList : public List<T>
{
protected:
    T* m_array;
    int m_length;
public:
      bool insert(int i, const T& e)
      {
          bool ret = false;
          if ( (i >=0)  && (i<=m_length)  && (m_length < capacity()))
          {
              for(int p=m_length-1; p >= i; p--)
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
      int length()const
      {
          return m_length;
      }
      void clear()
      {
          for(int i =0; i< m_length; i++)
          {
              m_array[i] = 0;
          }
          m_length = 0;
      }

      T& operator [] (int i)
      {
          if ((i >=0)  && (i<m_length))
          {
             return m_array[i];
          }
          else
          {

          }
      }

      T operator [](int i)const
      {
         return  const_cast<SeqList<T>&>(*this)[i];
      }
      virtual int capacity()const =0 ;

};
}
#endif // SEQLIST_H
