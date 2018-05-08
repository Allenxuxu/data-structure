#ifndef XXSTRING_H
#define XXSTRING_H

#include "Object.h"

namespace XXLib
{

class String : public Object
{
protected:
    char* m_str;
    size_t m_length;

    void init(const char* s);
    bool equal(const char* l, const char* r, size_t len) const;
public:
    String();
    String(const char c);
    String(const char *s);
    String(const String& s);

    size_t length()const;
    const char* str()const;

    bool operator == (const String& s) const;
    bool operator ==(const char* s)const;
    bool operator !=(const String& s) const;
    bool operator !=(const char* s) const;
    bool operator > (const String& s) const;
    bool operator > (const char* s) const;
    bool operator < (const String& s) const;
    bool operator < (const char* s) const;
    bool operator >= (const String& s) const;
    bool operator >= (const char* s) const;
    bool operator <= (const String& s) const;
    bool operator <= (const char* s) const;

    String operator + (const String& s) const;
    String operator + (const char* s) const;
    String& operator += (const String& s) ;
    String& operator  += (const char* s) ;

    String& operator = (const char* s) ;
    String& operator = (String s) ;
    String& operator = (char c) ;

    char& operator [] (int i);
    char operator [] (int i) const;
    bool startWith (char* s) const;
    bool startWith(String& s)const;
    bool endOf(char* s)const;
    bool endOf(String& s)const;

    String& insert(int i, const char* s);
    String& insert(int i, const String& s);

    String& trim();
    ~String();
};
}
#endif // XXSTRING_H
