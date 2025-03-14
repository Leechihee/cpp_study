#ifndef STONEWT_H_
#define STONEWT_H_
#include <iostream>

class Stonewt
{
    enum {Lbs_per_stn = 14};
    int stone;
    double pds_left;
    double pounds;
public:
    Stonewt(double lbs);
    Stonewt(int stn, double lbs);
    Stonewt();
    ~Stonewt();
    Stonewt operator+(const Stonewt &s) const {return Stonewt(pounds+s.pounds);}
    Stonewt operator-(const Stonewt &s) const {return Stonewt(pounds-s.pounds);}
    Stonewt operator*(const Stonewt &s) const {return Stonewt(pounds * s.pounds);}
    friend std::ostream & operator<<(std::ostream & os, const Stonewt & s);
};

#include "stonewt1.cpp"
#endif
