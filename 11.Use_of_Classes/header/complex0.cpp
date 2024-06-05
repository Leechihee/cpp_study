#include "complex0.h"

complex::complex()
{
    R = L = 0;
}

complex::complex(double r, double l)
{
    R = r;
    L = l;
}

bool operator>>(std::istream & is, complex &c)
{
    std::cout << "실수부 : ";
    while(!(is>>c.R))
    {
        return false;
    }
    std::cout << "허수부 : ";
    while(!(is>>c.L))
    {
        is.clear();
        while(is.get() != '\n')
            continue;
        std::cout << "실수를 입력하시오. : ";
    }
    return true;
}

std::ostream & operator<<(std::ostream & os, const complex &c)
{
    os << "(" << c.R << "," << c.L << "i)";
    return os;
}
