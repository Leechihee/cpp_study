#ifndef MYTIME_H_
#define MYTIME_H_
#include <iostream>

class Time
{
    int hours;
    int minutes;
public:
    Time();
    Time(int h, int m = 0);
    void AddMin(int m);
    void AddHr(int h);
    void reset(int h = 0, int m = 0);
    Time operator*(double n) const;
    friend Time operator+(const Time &t1, const Time &t2);
    friend Time operator-(const Time &t1, const Time &t2);
    friend Time operator*(double n, const Time &t) {return t*n;}
    friend std::ostream & operator<<(std::ostream & os, const Time &t);
};

#include "mytime.cpp"
#endif