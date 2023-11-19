#include <iostream>

using namespace std;

double light(double);

int main()
{
    cout << "광년 수를 입력하시오." << endl;
    double lyear;
    cin >> lyear;
    cout << lyear << "광년은 Au로 "
    << light(lyear) << "Au입니다." << endl;
    return 0;
}

double light(double n)
{
    return n*63240;
}
