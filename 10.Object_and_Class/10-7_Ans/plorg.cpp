#include <iostream>
#include "plorg.h"

Plorg::Plorg(char * Iname)
{
    for(int i = 0;Iname[i] != '\0';i++)
        name[i] = Iname[i];
}

void Plorg::setCI(int n)
{
    ci = n;
}

void Plorg::showPlorg() const
{
    using std::cout;
    using std::endl;
    cout << "Name : " << name << " / CI : " << ci << endl;
}
