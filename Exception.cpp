#include "Exception.h"
#include <cstring>
#include <cstdlib>

namespace XXLib
{
    void Exception::init(const char* messge, const char* file, int line)
    {
        m_message = _strdup(messge);
        if (file != NULL)
        {
            char sl[16] = { 0 };
            itoa(line, sl, 10);
            m_location = static_cast<char*>(malloc(strlen(file) + strlen(sl) + 2));
            if (m_location != NULL)
            {
                strcpy(m_location,file);
                strcat(m_location, ":");
                strcat(m_location,  sl);
            }
        }
        else
        {
            m_location = NULL;
        }
    }

    Exception::Exception(const char* message)
    {
        init(message, NULL, 0);
    }
    Exception::Exception(const char* file, int line)
    {
        init(NULL, file, line);
    }
    Exception::Exception(const char* messge, const char* file, int line)
    {
        init(messge, file, line);
    }

    Exception::Exception(const Exception& e)
    {
        m_message = _strdup(e.m_message);
        m_location = _strdup(e.m_location);
    }
    Exception& Exception::operator= (const Exception& e)
    {
        if (this != &e)
        {
            free(m_message);
            free(m_location);
            m_message = _strdup(e.m_message);
            m_location = _strdup(e.m_location);
        }
        return *this;
    }

    const char* Exception::message()const
    {
        return m_message;
    }
    const char* Exception::location()const
    {
        return m_location;
    }

    Exception::~Exception()
    {
        free(m_message);
        free(m_location);
    }
}
