//
// Created by dingguoliang on 2021/2/5.
//

#ifndef MYSTRING_H
#define MYSTRING_H

#include <cstring>


class String
{
public:
    String(const char* cstr = 0);
    String(const String& str);
    String& operator = (const String& str);
    char* get_c_str() const {return m_data;}
    ~String();
private:
    char* m_data;

};

String::String(const char *cstr)
{
    if(cstr)
    {
        m_data = new char[strlen(cstr) + 1];
        strcpy(m_data, cstr);
    }
    else
    {
        m_data = new char[1];
        m_data[0] = '\0';
    }
}
inline
String::String(const String &str)
{
    m_data = new char[strlen(str.m_data) + 1];
    strcpy(m_data, str.m_data);
}
inline
String::~String()
{
    delete [] m_data;
}
inline
String& String::operator = (const String &str)
{
    if(this == &str)
    {
        return *this;
    }
    delete [] m_data;
    m_data = new char[strlen(str.m_data) + 1];
    strcpy(m_data, str.m_data);
    return *this;
}

#include <iostream>

std::ostream& operator << (std::ostream& os, const String &s)
{
    os << s.get_c_str();
    return os;
}




#endif //HOUJIEPRAC_MYSTRING_H
