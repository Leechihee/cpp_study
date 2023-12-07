#include <iostream>

using namespace std;

float num(int,int);

int main()
{
    cout << "두개의 수를 입력하시오 (0을 입력하면 종료) : ";
    int a,b;
    while((cin >> a >> b) || a!=0 && b!=0)
        cout << num(a,b) << endl;
    cout << "종료합니다.";
    return 0;
}

float num(int a, int b)
{
    return 2.0*a*b/(a+b);
}
