#ifndef CIRCLELIST_H
#define CIRCLELIST_H
#include "LinkList.h"
namespace XXLib
{
template <typename T>
class CircleList : public LinkList<T>
{
protected:
    typedef typename LinkList<T>:: Node Node;

    int mod(int i) const
    {
        return (this->m_length == 0) ? 0 : ( i % this->m_length);
    }

    Node* last() const
    {
        return ( this->position(this->m_length - 1)->next );
    }

    void last_to_firist () const
    {
        last()->next = this->m_header.next;
    }
public:
    bool insert(const T& e)
    {
        return insert(this->m_length,e);
    }

    bool insert(int i, const T& e)
    {
        bool ret = true;

        i = i % (this->m_length + 1);
        ret = LinkList<T>::insert(i, e);

        if( ret && (i == 0))
        {
            last_to_firist();
        }
        return ret;
    }

    bool remove(int i)
    {
        bool ret = true;
        i = mod(i);
        if( i == 0)
        {
            Node* toDel = this->m_header.next;

            if( toDel != NULL)
            {
                this->m_header.next = toDel->next;
                this->m_length--;

                if(this->m_length > 0)
                {
                    last_to_firist();
                    if(this->m_current == toDel)
                    {
                        this->m_current = toDel->next;
                    }
                }
                else
                {
                    this->m_header.next =NULL;
                    this->m_current =NULL;
                }
                this->destroy(toDel);
            }
            else
            {
                ret = false;
            }

        }
        else
        {
            ret = LinkList<T>::remove(i);
        }

        return ret;
    }

    bool set(int i, const T &e)
    {
        return LinkList<T>::set(mod(i), e);
    }

    T get(int i) const
    {
        return LinkList<T>::get(mod(i));
    }

    bool get(int i, T& e)const
    {
        return LinkList<T>::get(mod(i),e);
    }

    int find(const T &e) const
    {
        int ret = -1;
        Node* slider = this->m_header.next;

        for(int i =0; i< this->m_length; i++)
        {
            if(slider->value == e )
            {
                ret = i;
                break;
            }

            slider = slider->next;

        }
        return ret;
    }

    void clear()
    {
        if(this->m_length > 0)
        {
            while(this->m_length > 1)
            {
                remove(1);
            }

            if(this->m_length == 1)
            {
                Node* toDel = this->m_header.next;
                this->m_header.next = NULL;
                this->m_current = NULL;
                this->m_length = 0;
                this->destroy(toDel);
            }
        }
    }

    bool move(int i, int step)
    {
        return LinkList<T>::move(mod(i),step);
    }

    bool next()
    {
        return LinkList<T>::next();
    }

    T current()
    {
        return LinkList<T>::current();
    }

    bool end()
    {
        return ((this->m_length == 0) || (this->m_current == NULL));
    }

    ~CircleList()
    {
        clear();
    }
};


}
#endif // CIRCLELIST_H
