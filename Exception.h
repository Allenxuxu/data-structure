#ifndef  EXCEPTION_H
#define  EXCEPTION_H

namespace XXLib
{
    class Exception
    {
    protected:
        char* m_message;
        char* m_location;
        void init(const char* messge, const char* file, int line);
    public:
        Exception(const char* message);
        Exception(const char* file, int line);
        Exception(const char* messge, const char* file, int line);

        Exception(const Exception& e);
        Exception& operator= (const Exception& e);

        virtual const char* message()const;
        virtual const char* location()const;

        virtual ~Exception();
    };
}
#endif
