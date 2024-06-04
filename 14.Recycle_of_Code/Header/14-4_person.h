#ifndef PERSON_H_
#define PERSON_H_

#include <string>

class Person{
    std::string fname;
    std::string lname;
protected:
    virtual void View() const;
    void data();
public:
    Person() : fname("None"), lname("None") {}
    Person(std::string f,std::string l) : fname(f), lname(l) {}
    Person(Person & p) : fname(p.fname), lname(p.lname) {}
    virtual void set() = 0;
    virtual ~Person() = 0;
    virtual void Show() const = 0;
};

class Gunslinger : virtual public Person{
    double Time;
    int notch;
    void infor_set();
protected:
    void View() const;
public:
    Gunslinger();
    Gunslinger(std::string f,std::string l);
    Gunslinger(Person & p);
    void set() {Person::data();}
    double Draw() const;
    void Show() const;
};

class PokerPlayer : virtual public Person{
    int card;
    void num_set();
public:
    PokerPlayer();
    PokerPlayer(std::string f,std::string l);
    PokerPlayer(Person & p);
    void set() {Person::data();}
    void Show() const;
    int Draw() const;
};

class BadDude : public Gunslinger, public PokerPlayer{
protected:
    void View() const;
public:
    BadDude() : Person(), Gunslinger(), PokerPlayer() {}
    BadDude(std::string f,std::string l) : Person(f,l), Gunslinger(f,l), PokerPlayer(f,l) {}
    BadDude(Person & p) : Person(p), Gunslinger(p), PokerPlayer(p) {}
    void set() {Person::data();}
    double Gdraw() const;
    int Cdraw() const;
    void Show() const;
};

#endif
