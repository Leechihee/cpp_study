#include <iostream>

using namespace std;

double fc(int);

int main()
{
    cout << "섭씨온도를 입력하시오." << endl;
    int input;
    cin >> input;
    cout << "섭씨온도 " << input << "은 화씨온도로 "
    << fc(input) << "도이다." << endl;
    return 0;
}
double fc(int n)
{
    return 1.8*n+32.0;
}

