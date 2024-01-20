#ifndef COMPLEX0_H_
#define COMPLEX0_H_
#include <iostream>

class complex{
    double R;
    double L;
    // R+Li
public:
    complex();
    complex(double r, double l);
    complex operator~() const {return complex(R,-L);}
    complex operator+(const complex & c) const {return complex(R+c.R,L+c.L);}
    complex operator-(const complex & c) const {return complex(R-c.R,L-c.L);}
    complex operator*(const complex & c) const {return complex(R*c.R-L*c.L,R*c.L+L*c.R);}
    complex operator*(double n) const {return complex(R*n,L*n);}
    friend complex operator*(double n,const complex & c) {return c*n;}
    friend bool operator>>(std::istream & is, complex &c);
    friend std::ostream & operator<<(std::ostream & os, const complex &c);
};

#endif
