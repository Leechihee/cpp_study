#include "string2.h"
#include <cctype>

namespace
{
    using namespace std;
}

int String::num_strings = 0;

String::String(const char *s)
{
    len = strlen(s);
    str = new char[len+1];
    strcpy(str,s);
    num_strings++;
}

String::String()
{
    len = 4;
    str = new char[1];
    str[0] = '\0';
    num_strings++;
}

String::String(const String &s)
{
    num_strings++;
    len = s.len;
    str = new char[s.len+1];
    strcpy(str,s.str);
}

String::~String()
{
    --num_strings;
    delete [] str;
}

void String::stringlow()
{
    for(int i = 0;str[i] != '\0';i++)
        str[i] = tolower(str[i]);
}

void String::stringup()
{
    for(int i = 0;str[i] != '\0';i++)
        str[i] = toupper(str[i]);
}

int String::has(const char ch)
{
    int ct = 0;
    int opch = toupper(ch);
    for(int i = 0;str[i] != '\0';i++)
    {
        if(str[i] == opch)
            ct++;
    }
    return ct;
}

String & String::operator=(const String & s)
{
    if(this == &s)
        return *this;
        
    delete [] str;
    len = s.len;
    str = new char[s.len+1];
    strcpy(str,s.str);
    return *this;
}

String & String::operator=(const char * s)
{
    delete [] str;
    len = strlen(s);
    str = new char[len+1];
    strcpy(str,s);
    return *this;
}

String & String::operator+(const String & s)
{
    char temp = *str;
    delete [] str;
    len = len+s.len;
    str = new char[len+1];
    str = strcat(temp,s.str);
    return *this;
}

String & String::operator+(const char* cs)
{
    char * temp = str;
    delete [] str;
    len = len+strlen(cs);
    str = new char[len+1];
    str = strcat(temp,cs);
    return *this;
}

ostream & operator<<(ostream & os, const String & s)
{
    os << s.str;
    return os;
}

istream & operator>>(istream & is, String & s)
{
    char temp[String::CINLIM];
    is.get(temp,String::CINLIM);
    if(is)
        s = temp;
    while(is && is.get() != '\n')
        continue;
    return is;
}
