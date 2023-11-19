#include <iostream>

using namespace std;

int old(int);

int main()
{
    cout << "현재 본인 나이를 입력하시오." << endl;
    int input_old;
    cin >> input_old;
    cout << "현재 나이를 월수로 나타낼 경우 "
    << old(input_old) << "입니다." << endl;
}

int old(int n)
{
    return n*12;
}
