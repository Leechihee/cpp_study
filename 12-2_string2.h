#include <iostream>
#include <cstring>
using std::ostream;
using std::istream;

class String{
    char * str;
    int len;
    static int num_strings;
    static const int CINLIM = 80;
public:
    String(const char *s);
    String();
    String(const String & s);
    ~String();
    int length() const {return len;}
    String & operator=(const String & s);
    String & operator=(const char * s);
    char & operator[](int i) {return str[i];}
    const char & operator[](int i) const {return str[i];}
    friend bool operator<(const String & s1, const String & s2) {return (strcmp(s1.str,s2.str) < 0);}
    friend bool operator>(const String & s1, const String & s2) {return s2 < s1;}
    friend bool operator==(const String &s1, const String & s2) {return (strcmp(s1.str,s2.str) == 0);}
    friend ostream & operator<<(const ostream & os, const String & s);
    friend istream & operator>>(const istream & is, const String & s);
    static int HowMany() {return num_strings;}
};
