#ifndef LINKLIST_H
#define LINKLIST_H
#include "List.h"
#include "Object.h"

namespace XXLib
{
template <typename T>
class LinkList : public List<T>
{
protected:
    struct Node :public Object
    {
        T value;
        Node* next;
    };
    mutable struct
    {
        char reserved[sizeof  T];
        Node* next;
    }m_header;
    int m_length;

    Node* position(int i) const
    {
        Node* ret = reinterpret_cast<Node*>(&m_header);
        for(int p =0; p<i; p++)
        {
            ret = ret->next;
        }
        return ret;
    }

public:
    LinkList()
    {
        m_length = 0;
        m_header.next = NULL;
    }

    bool insert(int i, const T& e)
    {

        Node* currect = position(i);

    }

    bool remove(int i)
    {

    }

    bool set(int i, const T& e)
    {

    }

    bool get(int i, T& e)const
    {

    }
    int length()const
    {

    }
    void clear()
    {

    }

    ~LinkList()
    {

    }
};

}

#endif // LINKLIST_H
