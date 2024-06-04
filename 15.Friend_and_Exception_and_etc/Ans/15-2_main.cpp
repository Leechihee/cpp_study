#include <iostream>
#include <cmath>
#include "excmean.h"

namespace
{
    using namespace std;
}

double hmean(double a, double b) throw(bad_hmean);
double gmean(double a, double b) throw(bad_gmean);

int main()
{
    double x, y, z;
    cout << "두 수를 입력하시오 : ";
    while(cin >> x >> y)
    {
        try
        {
            z = hmean(x,y);
            cout << x << ", " << y << "의 조화평균은 " << z << "입니다." << endl;
            cout << x << ", " << y << "의 기하평균은 " << gmean(x,y) << "입니다." << endl;
            cout << "다른 두 수를 입력하시오 (끝내려면 q) : ";
        }
        catch(bad_hmean & bad)
        {
            cout << bad.what() << endl;
            cout << "다시 입력하시오 : ";
            continue;
        }
        catch(bad_gmean & bad)
        {
            cout << bad.what() << endl;
            cout << "입력오류로 인한 프로그램 종료!" << endl;
            break;
        }
    }
    cout << "종료!";
    return 0;
}

double hmean(double a, double b) throw(bad_hmean)
{
    if(a == -b)
        throw bad_hmean();
    return 2.0 * a * b / (a+b);
}
double gmean(double a, double b) throw(bad_gmean)
{
    if(a < 0 || b < 0)
        throw bad_gmean();
    return sqrt(a*b);
}
