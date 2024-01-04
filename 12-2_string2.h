#include <iostream>
#include <cstring>
using std::ostream;
using std::istream;

class String{
    char * str;
    int len;
    static int num_strings;
public:
    String(const char *s);
    String();
    String(const String & s);
    ~String();
    int length() const {return len;}
    void stringlow();
    void stringup();
    int has(const char ch);
    String & operator=(const String & s);
    String & operator=(const char * s);
    String & operator+(const String & s);
    String & operator+(const char* cs);
    friend String & operator+(const char* cs, String &s) {return s+cs;}
    char & operator[](int i) {return str[i];}
    const char & operator[](int i) const {return str[i];}
    friend bool operator<(const String & s1, const String & s2) {return (strcmp(s1.str,s2.str) < 0);}
    friend bool operator>(const String & s1, const String & s2) {return s2 < s1;}
    friend bool operator==(const String &s1, const String & s2) {return (strcmp(s1.str,s2.str) == 0);}
    friend ostream & operator<<(ostream & os, const String & s);
    friend istream & operator>>(istream & is, String & s);
    static int HowMany() {return num_strings;}
    static const int CINLIM = 80;
};
