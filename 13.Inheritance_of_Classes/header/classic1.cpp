#include <iostream>
#include "classic1.h"

namespace
{
    using std::cout;
    using std::endl;
}
//Cd method
Cd::Cd(char * s1, char * s2, int n, double x)
{
    for(int i = 0;s1[i] != '\0';i++)
        performers[i] = s1[i];
    for(int i = 0;s2[i] != '\0';i++)
        label[i] = s2[i];
    selections = n;
    playtime = x;
}

Cd::Cd(const Cd & d)
{
    for(int i = 0;d.performers[i] != '\0';i++)
        performers[i] = d.performers[i];
    for(int i = 0;d.label[i] != '\0';i++)
        label[i] = d.label[i];
    selections = d.selections;
    playtime = d.playtime;
}

Cd::Cd()
{
    performers[0] = '\0';
    label[0] = '\0';
    selections = 0;
    playtime = 0.0;
}

Cd::~Cd(){}

void Cd::report() const
{
    cout << "Performers : " << performers << endl;
    cout << "Label : " << label << endl;
    cout << "Selections : " << selections << endl;
    cout << "Playtime : " << playtime << endl;
}

Cd & Cd::operator=(const Cd & d)
{
    if(this == &d)
        return *this;
    for(int i = 0;d.performers[i] != '\0';i++)
        performers[i] = d.performers[i];
    for(int i = 0;d.label[i] != '\0';i++)
        label[i] = d.label[i];
    selections = d.selections;
    playtime = d.playtime;
    return *this;
}

//Classic method
Classic::Classic(char * s1, char * s2, char * s3, int n, double x) : Cd(s1,s2,n,x)
{
    for(int i = 0;s3[i] != '\0';i++)
        pianist[i] = s3[i];
}

Classic::Classic(const Classic & cl) : Cd(cl)
{
    for(int i = 0;cl.pianist[i] != '\0';i++)
        pianist[i] = cl.pianist[i];
}

Classic::Classic() : Cd()
{
    pianist[0] = '\0';
}
void Classic::report() const
{
    Cd::report();
    cout << "Pianist : " << pianist << endl;
}

Classic & Classic::operator=(const Classic & cl)
{
    if(this == &cl)
        return *this;
    Cd::operator=(cl);
    for(int i = 0;cl.pianist[i] != '\0';i++)
        pianist[i] = cl.pianist[i];
    return *this;
}
