#include <iostream>

using namespace std;

double calculate(double,double,double *(pf)(double,double));

double add(double x, double y)
{
    return x+y;
}

double add2(double x, double y)
{
    return x*y;
}

int main()
{
    return 0;
}

double claculate(double,double,double *(pf)(double,double))
{
    double (*pfa[2])(double,double) = {add,add2};
    return 0;
}
