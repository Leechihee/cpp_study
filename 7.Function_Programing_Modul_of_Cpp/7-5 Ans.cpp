#include <iostream>

using namespace std;

long double factorial(int);

int main()
{
    cout << "수 하나를 입력하시오. : ";
    int number;
    while(!(cin >> number) || number < 0)
    {
        cin.clear();
        while(cin.get() != '\n')
            continue;
        if(number < 0)
            cout << "0 이상의 수를 입력하시오. : ";
        else
            cout << "숫자를 입력하시오. : ";
    }
    cout << number << "! = " << factorial(number);
    return 0;
}

long double factorial(int n)
{
    int count = n;
    int result;
    if(n==0)
        return 1;
    result = n*factorial(n-1);
    return result;
}
