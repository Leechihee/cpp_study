#include "cow.h"
#include <iostream>
#include <cstring>

namespace
{
    using namespace std;
}

Cow::Cow()
{
    name[0] = '\0';
    hobby = 0;
    weight = 0;
}

Cow::Cow(const char * nm, const char * ho, double wt)
{
    strcpy(name,nm);
    hobby = new char(strlen(ho)+1);
    strcpy(hobby,ho);
    weight = wt;
}

Cow::Cow(const Cow & c)
{
    strcpy(name,c.name);
    hobby = new char(strlen(c.hobby)+1);
    strcpy(hobby,c.hobby);
    weight = c.weight;
}

Cow::~Cow() {}

Cow & Cow::operator=(const Cow & c)
{
    if(this == &c)
        return *this;
    delete hobby;
    strcpy(name,c.name);
    hobby = new char(strlen(c.hobby)+1);
    strcpy(hobby,c.hobby);
    weight = c.weight;
    return *this;
}

void Cow::ShowCow() const
{
    cout << name << " " <<hobby << " " << weight << endl;
}
