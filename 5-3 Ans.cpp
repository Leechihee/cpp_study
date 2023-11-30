#include <iostream>

using namespace std;

int main()
{
    cout << "입력한 숫자들을 더하는 프로그램입니다.\n"
    << "0을 입력하면 프로그램이 종료하고 입력했던 숫자들을 합산하여 출력합니다.\n"
    << "숫자를 입력하시오. : ";
    int input, temp = 0;
    
    cin >> input;
    
    while(input != 0)
    {
        temp += input;
        cout << "또 다른 숫자를 입력하시오. : ";
        cin >> input;
    }
    cout << "지금까지 입력한 수를 합산한 값 : " << temp << "입니다.";
    return 0;
}
