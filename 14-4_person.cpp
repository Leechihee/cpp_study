#include "person.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

namespace
{
    using namespace std;
}

//Person protected method
void Person::View() const
{
    cout << "Name : " << fname << " " << lname << endl;
}

//Person public method
void Person::Show() const
{
    View();
}

//Gunslinger private method
void Gunslinger::infor_set()
{
    srand(time(0));
    Time = rand() % 3 + 1;
    notch = rand() & 10;
}

//Gunslinger protected method
void Gunslinger::View() const
{
    cout << "Time : " << Time << " Notch : " << notch << endl;
}

//Gunslinger public method
Gunslinger::Gunslinger(string f,string l) : Person(f,l)
{
    infor_set();
}

Gunslinger::Gunslinger(Person & p) : Person(p)
{
    infor_set();
}

void Gunslinger::Show() const
{
    Person::View();
    View();
}

//PokerPlayer private method
void PokerPlayer::num_set()
{
    srand(time(0));
    card = rand() % 52 + 1;
}
