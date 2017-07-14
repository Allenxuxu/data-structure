#ifndef SHAREDPOINTER_H
#define SHAREDPOINTER_H
#include <cstdlib>
#include "Pointer.h"
#include "Exception.h"

#include <iostream>
using namespace std;
namespace XXLib
{
template<typename T>
class SharedPointer: public Pointer<T>
{
    void assign(const SharedPointer<T>& obj)
    {
        this->m_ref = obj.m_ref;
        this->m_pointer = obj.m_pointer;
        if(this->m_ref)
        {
            (*(this->m_ref))++;
        }
    }

protected:
    int* m_ref;
public:
    SharedPointer(T* p=NULL): Pointer<T>(NULL),m_ref(NULL)
    {
        if(p)
        {
            this->m_ref = static_cast<int*>(std::malloc(sizeof(int)));
            if(this->m_ref)
            {
                this->m_pointer = p;
                *(this->m_ref) = 1;
            }
            else
            {
                THROW_EXCEPTION(NoEnoughtMemoryException,"no memory to reate SharedPointer object ..");
            }
        }
    }
    SharedPointer(const SharedPointer<T>& obj):Pointer<T>(NULL)
    {
        assign(obj);
    }

    SharedPointer<T>& operator = (const SharedPointer<T>& obj)
    {
        if(&obj != this)
        {
           clear();
           assign(obj);
        }
        return *this;
    }

    void clear()
    {
        T* toDel =this->m_pointer;
        int* ref = this->m_ref;

        this->m_pointer = NULL;
        this->m_ref = NULL;

        if(ref)
        {
              (*ref)--;
            if(*ref == 0)
            {
                free(ref);
                delete toDel;
            }
        }
    }

    ~SharedPointer()
    {
        clear();
    }

};
template <typename T>
bool operator ==(const SharedPointer<T>& l,const SharedPointer<T>& r)
{
    return (l.get() == r.get());
}

template <typename T>
bool operator !=(const SharedPointer<T>& l,const SharedPointer<T>& r)
{
    return !(l == r);
}
}
#endif // SHAREDPOINTER_H
