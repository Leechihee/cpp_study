#include <iostream>

using namespace std;

int main()
{
    cout << "당신의 키는 몇 cm입니까? ___cm\b\b\b\b\b";
    const int insu = 100;
    int toil;
    double output;
    cin >> toil;
    output = double (toil) / double (insu);
    cout << "\n당신의 키는 " << output << "m입니다.";
    return 0;
}
