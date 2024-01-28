#ifndef PERSON_H_
#define PERSON_H_
#include <string>

class Person{
    string fname;
    string lname;
protected:
    virtual void View() const;
public:
    Person() : fname("None"), lname("None") {}
    Person(string f,string l) : fname(f), lname(l) {}
    virtual ~Person() = 0;
    virtual void Show() const = 0;
};

class Gunslinger : virtual public Person{
    double Time;
    int notch;
    void time_set();
protected:
    void View() const;
public:
    Gunslinger();
    Gunslinger(string f,string l);
    Gunslinger(Person & p);
    double Draw() const;
    void Show() const;
};

class PokerPlayer : virtual public Person{
    int card;
    void num_set();
public:
    PokerPlayer();
    PokerPlayer(string f,string l);
    PokerPlayer(Person & p);
    int Draw() const;
};

class BadDude : public Gunslinger, public PokerPlayer{
protected:
    void View() const;
public:
    BadDude();
    BadDude(string f,string l);
    BadDude(Person & p);
    double Gdraw() const;
    int Cdraw() const;
    void Show() const;
};

#endif
