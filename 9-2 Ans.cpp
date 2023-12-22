#include <iostream>
#include <string>

namespace
{
    using namespace std;
}

void strcount(const string str);

int main()
{
    string str;
    cout << "문자열을 입력하시오.\n";
    getline(cin,str);
    while(str != "")
    {
        strcount(str);
        cout << "다음 행을 입력하시오. (끝내려면 빈칸입력) : \n";
        getline(cin,str);
    }
    cout << "종료!";
    return 0;
}

void strcount(const string str)
{
    static int total = 0;
    int count = 0;
    
    cout << "\"" << str << "\"에는 ";
    while(str[count])
        count++;
    total += count;
    cout << count << "개의 문자가 있습니다.\n";
    cout << "지금까지 총 " << total << "개의 문자를 읽었습니다.\n";
}
