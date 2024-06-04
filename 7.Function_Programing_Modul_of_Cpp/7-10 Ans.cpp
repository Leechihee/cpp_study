#include <iostream>

using namespace std;

const int size = 2;

double calculate(double,double,double (*pfa[])(double,double));

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
    double (*pfa[size])(double,double) = {add, add2};
    double a,b,q;
    cout << "입력 오류시 프로그램 종료.\n";
    cout << "두 수를 입력하시오. (소숫점 가능) : ";
    while(cin>> a >> b)
    {
        q = calculate(a,b,pfa);
        cout << "(" << a << " + " << b << ") + (" << a << "*" << b << ") = ";
        cout << q << endl;
        cout << "두 수를 입력하시오. (소숫점 가능) : ";
    }
    cout << "입력 오류! 프로그램 종료!";
    
    return 0;
}

double calculate(double a,double b ,double (*pfa[])(double,double))
{
    double temp = 0.0;
    for(int i = 0;i<size;i++)
        temp += pfa[i](a,b);
    return temp;
}
