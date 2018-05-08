#ifndef CHECKEDDELETE
#define CHECKEDDELETE

namespace XXLib
{
    // verify that types are complete for increased safety

    template<class T> inline void checked_delete(T * x)
    {
        // intentionally complex - simplification causes regressions
        typedef char type_must_be_complete[ sizeof(T)? 1: -1 ];
        (void) sizeof(type_must_be_complete);
        delete x;
    }

    template<class T> inline void checked_array_delete(T * x)
    {
        typedef char type_must_be_complete[ sizeof(T)? 1: -1 ];
        (void) sizeof(type_must_be_complete);
        delete [] x;
    }

}

#endif // CHECKEDDELETE

