#pragma once
#ifndef  SMARTPOINT_H
#define  SMARTPOINT_H
#include "Pointer.h"
#include "CheckedDelete.h"

namespace XXLib
{
    template<typename T>
    class ScopedPointer : public Pointer<T>
    {
    private:
        ScopedPointer(const ScopedPointer<T>&);
        ScopedPointer<T>& operator = (const ScopedPointer<T>&);

        void operator==( ScopedPointer const& ) const;
        void operator!=( ScopedPointer const& ) const;
    public:
        ScopedPointer(T* p = NULL): Pointer<T>(p)
        {}

        void reset(T* p = NULL)
        {
            ScopedPointer<T>(p).swap(*this);
        }

        void swap(ScopedPointer & b)
        {
            T * tmp = b.m_pointer;
            b.m_pointer = this->m_pointer;
            this->m_pointer = tmp;
        }

        ~ScopedPointer()
        {
            checked_delete<T>(this->m_pointer);
        }

    };
}
#endif
