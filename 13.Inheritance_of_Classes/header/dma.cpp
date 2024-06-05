#include "dma.h"
#include <cstring>
#include <iostream>

namespace
{
    using namespace std;
}
//abcDMA method
abcDMA::abcDMA(const char * lb, int r)
{
    label = new char[strlen(lb)+1];
    strcpy(label,lb);
    rating = r;
}

abcDMA::abcDMA(const abcDMA & aD)
{
    label = new char[strlen(aD.label)+1];
    strcpy(label,aD.label);
    rating = aD.rating;
}

abcDMA::~abcDMA()
{
    delete [] label;
}

void abcDMA::View() const
{
    cout << "Label : " << label << endl;
    cout << "Rating : " << rating << endl;
}

abcDMA & abcDMA::operator=(const abcDMA & aD)
{
    if(this == &aD)
        return *this;
    delete label;
    label = new char[strlen(aD.label)+1];
    strcpy(label,aD.label);
    rating = aD.rating;
    return *this;
}
//baseDMA method
baseDMA::baseDMA(const char * lb, int r) : abcDMA(lb,r) {}

baseDMA::baseDMA(const baseDMA & bD) : abcDMA(bD) {}

baseDMA::~baseDMA() {}

void baseDMA::View() const
{
    abcDMA::View();
}

baseDMA & baseDMA::operator=(const baseDMA & bD)
{
    if(this == &bD)
        return *this;
    baseDMA::operator=(bD);
    return *this;
}

//lacksDMA method
lacksDMA::lacksDMA(const char * lb , int r ,const char * co) : abcDMA(lb,r)
{
    color = new char[strlen(co)+1];
    strcpy(color,co);
}

lacksDMA::lacksDMA(const lacksDMA & lD) : abcDMA(lD)
{
    color = new char[strlen(lD.color)+1];
    strcpy(color,lD.color);
}

lacksDMA::~lacksDMA()
{
    delete [] color;
}

void lacksDMA::View() const
{
    abcDMA::View();
    cout << "Color : " << color << endl;
}

lacksDMA & lacksDMA::operator=(const lacksDMA & lD)
{
    if(this == &lD)
        return *this;
    abcDMA::operator=(lD);
    delete [] color;
    color = new char[strlen(lD.color)+1];
    strcpy(color,lD.color);
    return *this;
}

//hasDMA method
hasDMA::hasDMA(const char * lb , int r, const char * st) : abcDMA(lb,r)
{
    style = new char[strlen(st)+1];
    strcpy(style,st);
}

hasDMA::hasDMA(const hasDMA & hD) : abcDMA(hD)
{
    style = new char[strlen(hD.style)+1];
    strcpy(style,hD.style);
}

hasDMA::~hasDMA()
{
    delete [] style;
}

void hasDMA::View() const
{
    abcDMA::View();
    cout << "Style : " << style << endl;
}

hasDMA & hasDMA::operator=(const hasDMA & hD)
{
    if(this == &hD)
        return *this;
    abcDMA::operator=(hD);
    delete [] style;
    style = new char[strlen(hD.style)+1];
    strcpy(style,hD.style);
    return *this;
}
