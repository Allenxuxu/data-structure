#ifndef  LIST_H
#define LIST_H
#include "Object.h"

namespace   XXLib
{
    template <typename  T>
    class List : public Object
    {
    protected:
        List(const List& );                             //链表不允许进行拷贝构造
        List& operator = (const List&);                 //链表不允许进行复制操作
    public:
        List(){}

        void push_back(const T& e)
        {
            insert(e);
        }

        void push_front(const T& e)
        {
            insert(0,e);
        }

        void pop_back()
        {
            remove(length() - 1);
        }

        void pop_front()
        {
            remove(0);
        }

        T back() const
        {
            return get(length() - 1);
        }

        T front() const
        {
            return get(0);
        }

        virtual  bool insert(const T& e)=0;
        virtual  bool insert(int i, const T& e)=0;
        virtual  bool remove(int i)=0;
        virtual  bool set(int i, const T& e)=0;
        virtual  bool get(int i, T& e)const =0;
        virtual  T get(int i) const=0;
        virtual  int find(const T& e) const =0;
        virtual  int length()const =0;
        virtual  void clear()=0;
    };
}
#endif // LIST_H
