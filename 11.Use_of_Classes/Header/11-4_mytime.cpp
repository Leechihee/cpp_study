#include "mytime.h"

Time::Time()
{
    hours = minutes = 0;
}

Time::Time(int h, int m)
{
    hours = h;
    minutes = m;
}

void Time::AddMin(int m)
{
    minutes += m;
    hours += minutes/60;
    minutes %= 60;
}

void Time::AddHr(int h)
{
    hours += h;
}

void Time::reset(int h, int m)
{
    hours = h;
    minutes = m;
}

Time Time::operator*(double n) const
{
    Time result;
    result.AddMin(hours*n*60+minutes*n);
    return result;
}

Time operator+(const Time &t1, const Time &t2)
{
    Time result;
    long totalmin = t1.hours*60 + t1.minutes + t2.hours*60 + t2.minutes;
    result.AddMin(totalmin);
    return result;
}

Time operator-(const Time &t1, const Time &t2)
{
    Time result;
    long totalmin = (t1.hours*60 + t1.minutes) - (t2.hours*60 + t2.minutes);
    result.AddMin(totalmin);
    return result;
}

std::ostream & operator<<(std::ostream & os, const Time &t)
{
    os << t.hours << "시간, " << t.minutes << "분";
    return os;
}

