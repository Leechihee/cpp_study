#include <iostream>
#include "person.h"

namespace
{
    using std::cout;
    using std::endl;
}

person::person(const string &ln, const char fn[])
{
    lname = ln;
    for(int i = 0;fn[i] != '\0';i++)
        fname[i] = fn[i];
}

void person::Show() const
{
    cout << lname << " " << fname << "님" << endl;
}

void person::FormalShow() const
{
    cout << fname << " " << lname << "님" << endl;
}
