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

void Person::data()
{
    cout << "Enter first name : ";
    getline(cin, fname);
    cout << "Enter last name: ";
    getline(cin, lname);
}

//Person public method
Person::~Person() {}

void Person::Show() const
{
    View();
}

//Gunslinger private method
void Gunslinger::infor_set()
{
    srand(time(0));
    Time = rand() % 3 + 1 + rand() % 10 * 0.1;
    notch = rand() & 10;
}

//Gunslinger protected method
void Gunslinger::View() const
{
    cout << "Time : " << Time << " / Notch : " << notch << endl;
}

//Gunslinger public method
Gunslinger::Gunslinger() : Person()
{
    infor_set();
}

Gunslinger::Gunslinger(string f,string l) : Person(f,l)
{
    infor_set();
}

Gunslinger::Gunslinger(Person & p) : Person(p)
{
    infor_set();
}

double Gunslinger::Draw() const
{
    return Time;
}

void Gunslinger::Show() const
{
    cout << "Gunslinger\n";
    Person::View();
    View();
    cout << "Gun Draw Time : " << Draw() << endl;
}

//PokerPlayer private method
void PokerPlayer::num_set()
{
    srand(time(0));
    card = rand() % 52 + 1;
}

//PokerPlayer public method
PokerPlayer::PokerPlayer() : Person()
{
    num_set();
}

PokerPlayer::PokerPlayer(string f,string l) : Person(f,l)
{
    num_set();
}

PokerPlayer::PokerPlayer(Person & p) : Person(p)
{
    num_set();
}

void PokerPlayer::Show() const
{
    cout << "PokerPlayer\n";
    Person::Show();
}

int PokerPlayer::Draw() const
{
    return card;
}

//BadDude protected method
void BadDude::View() const
{
    Person::View();
    Gunslinger::View();
}

//BadDude public method
double BadDude::Gdraw() const
{
    return Gunslinger::Draw();
}

int BadDude::Cdraw() const
{
    return PokerPlayer::Draw();
}

void BadDude::Show() const
{
    cout << "BadDude\n";
    View();
    cout << "Gun Draw Time : " << Gdraw() << endl;
    cout << "Card Draw Number : " << Cdraw() << endl;
}
