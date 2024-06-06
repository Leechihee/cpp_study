#include "port.h"
#include <cstring>

//Port method
Port::Port(const char * br, const char * st, int b) : bottles(b)
{
    brand = new char[strlen(br)+1];
    strcpy(brand,br);
    for(int i = 0;st[i] != '\0';i++)
        style[i] = st[i];
}

Port::Port(const Port & p) : bottles(p.bottles)
{
    brand = new char[strlen(p.brand)+1];
    strcpy(brand,p.brand);
    for(int i = 0;p.style[i] != '\0';i++)
        style[i] = p.style[i];
}

Port & Port::operator=(const Port & p)
{
    if(this == &p)
        return *this;
    delete [] brand;
    brand = new char[strlen(p.brand)+1];
    strcpy(brand,p.brand);
    for(int i = 0;p.style[i] != '\0';i++)
        style[i] = p.style[i];
    bottles = p.bottles;
    return *this;
}

Port & Port::operator+=(int b)
{
    bottles += b;
    return *this;
}

Port & Port::operator-=(int b)
{
    if(bottles < b)
    {
        cout << "입력값이 보유량보다 많습니다." << endl;
        return *this;
    }
    else
    {
        bottles -= b;
        return *this;
    }
}

void Port::Show() const
{
    cout << "Brand : " << brand << endl;
    cout << "Style : " << style << endl;
    cout << "Bottlse : " << bottles << endl;
}

ostream & operator<<(ostream & os, const Port & p)
{
    os << p.brand << ", " << p.style << ", " << p.bottles;
    return os;
}

//VintagePort method
VintagePort::VintagePort() : Port(), year(0)
{
    nickname = new char[strlen("None")+1];
    strcpy(nickname,"None");
}

VintagePort::VintagePort(const char * br,int b, const char * nn, int y) : Port(br,"Vintage", b), year(y)
{
    nickname = new char[strlen(nn)+1];
    strcpy(nickname,nn);
}

VintagePort::VintagePort(const VintagePort & vp) : Port(vp), year(vp.year)
{
    nickname = new char[strlen(vp.nickname)+1];
    strcpy(nickname,vp.nickname);
}

VintagePort & VintagePort::operator=(const VintagePort & vp)
{
    if(this == &vp)
        return *this;
    Port::operator=(vp);
    delete [] nickname;
    nickname = new char[strlen(vp.nickname)+1];
    strcpy(nickname,vp.nickname);
    year = vp.year;
    return *this;
}

void VintagePort::Show() const
{
    Port::Show();
    cout << "Nickname : " << nickname << endl;
    cout << "Year : " << year << endl;
}

ostream & operator<<(ostream & os, const VintagePort & vp)
{
    operator<<(os,(Port)vp);
    os << ", " << vp.nickname << ", " << vp.year;
    return os;
}
