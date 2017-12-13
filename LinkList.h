#ifndef LINKLIST_H
#define LINKLIST_H
#include "List.h"
#include "Object.h"
#include "Exception.h"

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

    mutable struct : public Object
    {
        char reserved[sizeof ( T)];
        Node* next;
    }m_header;

   // Node m_header;

    int m_length;
    int m_step;
    Node* m_current;

    Node* position(int i) const
    {
       Node* ret = reinterpret_cast<Node*>(&m_header);

        for(int p =0; p<i; p++)
        {
            ret = ret->next;
        }

        return ret;
    }

    virtual Node* create()
    {
        return new Node();
    }

    virtual void destroy(Node* pn)
    {
        delete pn;
    }

public:
    LinkList()
    {
        m_header.next = NULL;
        m_length = 0 ;
        m_current =NULL;
        m_step = 0;
    }

    bool insert(const T& e)
    {
        return insert(m_length,e);
    }

    bool insert(int i, const T& e)
    {
           bool ret = (i >= 0) && (i <= m_length);
           if(ret)
           {
               Node* node = create();

               if(node != NULL)
               {
                    Node* currect = position(i);

                    node->value = e;
                    node->next = currect->next;
                    currect->next = node;
                    m_length++;
               }
               else
               {
                    THROW_EXCEPTION(NoEnoughtMemoryException,"No memory to insert new element ...");
               }
           }
           return ret;
    }

    bool remove(int i)
    {
        bool ret = (i<=m_length)&&(i>=0);
        if(ret)
        {
            Node* currect = position(i);
            Node* toDel = currect->next;
            if(m_current == toDel)
            {
                m_current = toDel->next;
            }
            currect->next = toDel->next;
            m_length--;
            destroy(toDel);        
        }
        return ret;
    }

    bool set(int i, const T& e)
    {
         bool ret = (i<=m_length)&&(i>=0);
         if(ret)
         {
             position(i)->next->value = e;
         }
         return ret;
    }

    virtual  T get(int i) const
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

    bool get(int i, T& e)const
    {
        bool ret = (i<=m_length)&&(i>=0);
        if(ret)
        {
            e = position(i)->next->value;
        }
        return ret;
    }

   int find(const T& e) const
    {
        int ret = -1;
        int i =0;
        Node * node = m_header.next;

        while(node)
        {
            if(node->value == e)
            {
                ret = i;
                break;
            }
            else
            {
                node = node->next;
                i++;
            }
        }
        return ret;
    }

    int length()const
    {
        return m_length;
    }
    void clear()
    {
        while(m_header.next)
        {
            Node* toDel = m_header.next;
            m_header.next = toDel->next;
            m_length--;
            destroy(toDel);
        }
    }

    virtual bool move(int i, int step = 1)
    {
            bool ret = (i >= 0) && (i < m_length) && (step >0);
            if(ret)
            {
                m_current = position(i)->next;
                m_step = step;
            }

            return ret;
    }

    virtual bool next()
    {
        int i = 0;
        while ((i < m_step) && (!end()))
        {
            m_current = m_current->next;
            i++;
        }
        return (i == m_step);
    }

    virtual T current()
    {
        if( !end() )
        {
            return m_current->value;
        }
        else
        {
                THROW_EXCEPTION(InvalidParameterException,"No value at current position ...");
        }
    }

    virtual bool end()
    {
        return (m_current == NULL);
    }


    ~LinkList()
    {
        clear();
    }
};

}

#endif // LINKLIST_H
