#include <iostream>
#include "classic.h"
#include <cstring>

namespace
{
    using namespace std;
}
//Cd method
Cd::Cd(char * s1, char * s2, int n, double x)
{
    performers = new char[strlen(s1)+1];
    strcpy(performers,s1);
    label = new char[strlen(s2)+1];
    strcpy(label,s2);
    selections = n;
    playtime = x;
}

Cd::Cd(const Cd & d)
{
    performers = new char[strlen(d.performers)+1];
    strcpy(performers,d.performers);
    label = new char[strlen(d.label)+1];
    strcpy(label,d.label);
    selections = d.selections;
    playtime = d.playtime;
}

Cd::Cd()
{
    performers = new char[4];
    performers[0] = '\0';
    label = new char[4];
    label[0] = '\0';
    selections = 0;
    playtime = 0.0;
}

Cd::~Cd()
{
    delete [] performers;
    delete [] label;
}

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
    delete [] performers;
    delete [] label;
    performers = new char[strlen(d.performers)+1];
    strcpy(performers,d.performers);
    label = new char[strlen(d.label)+1];
    strcpy(label,d.label);
    selections = d.selections;
    playtime = d.playtime;
    return *this;
}

//Classic method
Classic::Classic(char * s1, char * s2, char * s3, int n, double x) : Cd(s1,s2,n,x)
{
    pianist = new char[strlen(s3)+1];
    strcpy(pianist,s3);
}

Classic::Classic(const Classic & cl) : Cd(cl)
{
    pianist = new char[strlen(cl.pianist)+1];
    strcpy(pianist,cl.pianist);
}

Classic::Classic() : Cd()
{
    pianist = new char[4];
    pianist[0] = '\0';
}

Classic::~Classic()
{
    delete [] pianist;
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
    delete [] pianist;
    pianist = new char[strlen(cl.pianist)+1];
    strcpy(pianist,cl.pianist);
    return *this;
}
