#include <iostream>

using namespace std;

long double probability(double, double, double);
int main()
{
    double total, choices, bonus;
    cout << "전체 수의 개수와 뽑을 수의 개수, 보너스 볼의 개수를 입력하시오.\n";
    while((cin >> total >> choices >> bonus) && choices < total && bonus !=0)
    {
        cout << "당신이 1등을 할 확률은 : ";
        cout << probability(total, choices, bonus);
        cout << "번 중 한번입니다.\n";
        cout << "다시 세 수를 입력하시오.(q를 입력하면 종료) : ";
    }
    return 0;
}

long double probability(double to, double ch, double bn)
{
    long double result = 1.0;
    long double n;
    unsigned p;
    for(n=to,p=ch; p>0;n--,p--)
    {
        result = result * n/p;
    }
    return result*bn;
}
