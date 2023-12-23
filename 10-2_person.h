#include <iostream>
#include <string>

namespace
{
    using std::string;
}

class person{
    static const int LIMIT = 25;
    string lname;
    char fname[LIMIT];
public:
    person() {lname = ""; fname[0]='\0';};
    person(const string &ln, const char fn[] = "Heyyou");
    void Show() const;
    void FormalShow() const;
};
