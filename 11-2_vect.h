#ifndef VECT_H_
#define VECT_H_
#include <iostream>
#include <cmath>

namespace VECTOR
{
    class Vector{
        enum Mode {RECT,POL};
        double x;
        double y;
        Mode mode;
        void set_x(double n1, double n2);
        void set_y(double n1, double n2);
    public:
        Vector();
        Vector(double n1, double n2, char form = 'r');
        void reset(double n1, double n2, char form = 'r');
        ~Vector();
        double xval() const {return x;}
        double yval() const {return y;}
        double magval() const {return sqrt(x*x + y*y);}
        double angval() const
        {
            if(x== 0.0 && y==0.0)
                return 0.0;
            else
                return atan2(y,x);
        }
        void polar_mode();
        void rect_mode();
        Vector operator+(const Vector &v) const;
        Vector operator-(const Vector &v) const;
        Vector operator-() const;
        Vector operator*(double n) const;
        friend Vector operator*(double n, const Vector &v);
        friend std::ostream & operator<<(std::ostream & os, const Vector &v);
    };
}

#endif
