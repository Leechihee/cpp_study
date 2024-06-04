#include <iostream>
#include <string>

using namespace std;

int main()
{
    string firstname, lastname;
    cout << "당신의 영문이름을 입력하시오 : ";
    getline(cin,firstname);
    cout << "당신의 영문 성을 입력하시오 : ";
    getline(cin,lastname);
    cout << "하나의 문자열로 만들면 " << lastname << ", " << firstname;
    return 0;
}
