#include <iostream>
#include <cctype>

using namespace std;

int main()
{
    cout << "영문자를 입력하시오. (대문자는 소문자로, 소문자는 대문자로 변환한다.) \n";
    char ch;
    while(cin.get(ch) && ch !='@')
    {
        if(ch >='a' && ch<='z')
            cout << char(toupper(ch));
        else if(ch>='A' && ch<='Z')
            cout << char(tolower(ch));
        else
            cout << ch;
    }
    return 0;
}
