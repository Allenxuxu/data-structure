#ifndef SHAREDPOINTER_H
#define SHAREDPOINTER_H

#include "Pointer.h"
#include "Exception.h"
#include "CheckedDelete.h"

namespace XXLib
{
    template<typename T>
    class SharedPointer: public Pointer<T>
    {
    public:
        SharedPointer(T* p=NULL): Pointer<T>(NULL),m_ref(NULL)
        {
           assign(p);
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

        void reset(T* p=NULL)
        {
            clear();
            assign(p);
        }

        ~SharedPointer()
        {
            clear();
        }

        int useCount() const
        {
            return (m_ref == NULL) ? 0 : *m_ref;
        }

        bool unique() const
        {
            return useCount() == 1;
        }

    private:
        void assign(const SharedPointer<T>& obj)
        {
            this->m_ref = obj.m_ref;
            this->m_pointer = obj.m_pointer;
            if(this->m_ref)
            {
                (*this->m_ref)++;
            }
        }

        void assign(T* p)
        {
            if(p)
            {
                this->m_ref = static_cast<int*>(new int(0));
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
                    delete ref;
                    checked_delete<T>(toDel);
                }
            }
        }

    protected:
        int* m_ref;

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
