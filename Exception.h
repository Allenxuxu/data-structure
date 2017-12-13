#ifndef   EXCEPTION_H
#define  EXCEPTION_H

namespace XXLib
{

#define THROW_EXCEPTION(e,m)  (throw  e(m,__FILE__,__LINE__))
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

    virtual ~Exception()=0;
};

class ArithmeticException : public Exception
{
public:
    ArithmeticException ():Exception(0) { }
    ArithmeticException (const char* message):Exception(message) { }
    ArithmeticException (const char* file,int line):Exception(file,line) { }
    ArithmeticException (const char* message,const char* file,int line) :Exception(message,file,line) { }

    ArithmeticException& operator =(const ArithmeticException& e)
    {
        Exception::operator =(e);
        return *this;
    }
};

class  NullPointerException : public Exception
{
public :
    NullPointerException ():Exception (0) {}
    NullPointerException (const char* message):Exception(message) {}
    NullPointerException(const char * file,int line):Exception(file,line){}
    NullPointerException(const char* message,const char *file, int line):Exception(message,file,line){}
    NullPointerException& operator =(const  NullPointerException& e)
    {
        Exception::operator =(e);
        return *this;
    }
};

class  IndexOutOfBoundsException : public Exception
{
public :
    IndexOutOfBoundsException ():Exception (0) {}
    IndexOutOfBoundsException (const char* message):Exception(message) {}
    IndexOutOfBoundsException(const char * file,int line):Exception(file,line){}
    IndexOutOfBoundsException(const char* message,const char *file, int line):Exception(message,file,line){}
    IndexOutOfBoundsException& operator =(const  IndexOutOfBoundsException& e)
    {
        Exception::operator =(e);
        return *this;
    }
};

class  NoEnoughtMemoryException : public Exception
{
public :
    NoEnoughtMemoryException ():Exception (0) {}
    NoEnoughtMemoryException (const char* message):Exception(message) {}
    NoEnoughtMemoryException(const char * file,int line):Exception(file,line){}
    NoEnoughtMemoryException(const char* message,const char *file, int line):Exception(message,file,line){}
    NoEnoughtMemoryException& operator =(const  NoEnoughtMemoryException& e)
    {
        Exception::operator =(e);
        return *this;
    }
};
class  InvalidParameterException : public Exception
{
public :
    InvalidParameterException ():Exception (0) {}
    InvalidParameterException (const char* message):Exception(message) {}
    InvalidParameterException(const char * file,int line):Exception(file,line){}
    InvalidParameterException(const char* message,const char *file, int line):Exception(message,file,line){}
    InvalidParameterException& operator =(const  InvalidParameterException& e)
    {
        Exception::operator =(e);
        return *this;
    }
};

class  InvalidOperationException : public Exception
{
public :
    InvalidOperationException ():Exception (0) {}
    InvalidOperationException (const char* message):Exception(message) {}
    InvalidOperationException(const char * file,int line):Exception(file,line){}
    InvalidOperationException(const char* message,const char *file, int line):Exception(message,file,line){}
    InvalidOperationException& operator =(const  InvalidParameterException& e)
    {
        Exception::operator =(e);
        return *this;
    }
};
}



#endif
