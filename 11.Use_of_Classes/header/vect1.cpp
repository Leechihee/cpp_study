#include "vect1.h"
#include <cmath>
#include <cctype>

namespace VECTOR
{
    const double Rad_to_deg = 45.0 / atan(1.0);
    
    void Vector::set_mag()
    {
        mag = sqrt(x*x + y*y);
    }
    
    void Vector::set_ang()
    {
        if(x== 0.0 && y==0.0)
            ang = 0.0;
        else
            ang = atan2(y,x);
    }
    
    void Vector::set_x()
    {
        x = mag * cos(ang);
    }
    
    void Vector::set_y()
    {
        y = mag * sin(ang);
    }
    
    Vector::Vector()
    {
        x = y = 0;
        mode = RECT;
    }
    
    Vector::Vector(double n1, double n2, char form)
    {
        if(toupper(form) == 'R')
        {
            mode = RECT;
            x = n1; y = n2;
            set_mag(); set_ang();
        }
        else if(toupper(form) == 'P')
        {
            mode = POL;
            mag = n1; ang = n2/Rad_to_deg;
            set_x(); set_y();
        }
        else
        {
            std::cout << "제 3의 매개변수 입력오류!" << std::endl;
            std::cout << "벡터를 0으로 설정!\n";
            x = y = 0;
            mode = RECT;
        }
    }
    
    void Vector::reset(double n1, double n2, char form)
    {
        if(toupper(form) == 'R')
        {
            mode = RECT;
            x = n1; y = n2;
            set_mag(); set_ang();
        }
        else if(toupper(form) == 'P')
        {
            mode = POL;
            mag = n1; ang = n2/Rad_to_deg;
            set_x(); set_y();
        }
        else
        {
            std::cout << "제 3의 매개변수 입력오류!" << std::endl;
            std::cout << "벡터를 0으로 설정!\n";
            x = y = 0;
            mode = RECT;
        }
    }
    
    Vector::~Vector() {}
    
    void Vector::polar_mode()
    {
        mode = POL;
    }
    
    void Vector::rect_mode()
    {
        mode = RECT;
    }
    
    Vector Vector::operator+(const Vector &v) const
    {
        return Vector(x + v.x, y+v.y);
    }
    
    Vector Vector::operator-(const Vector &v) const
    {
        return Vector(x-v.x, y-v.y);
    }
    
    Vector Vector::operator-() const
    {
        return Vector(-x,-y);
    }
    
    Vector Vector::operator*(double n) const
    {
        return Vector(x*n,y*n);
    }
    
    Vector operator*(double n, const Vector &v)
    {
        return v * n;
    }
    
    std::ostream & operator<<(std::ostream & os, const Vector &v)
    {
        if(v.mode == Vector::RECT)
            os << "(x,y) = (" << v.x << ", " << v.y << ")";
        else if(v.mode == Vector::POL)
        {
            os << "(m,a) = (" << v.mag << ", " << v.ang/Rad_to_deg << ")";
        }
        else
            os << "Vector 객체의 모드 지정이 틀렸습니다.\n";
        return os;
    }
}
