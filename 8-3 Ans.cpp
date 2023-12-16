#include <iostream>
#include <string>
using namespace std;

void get_to_up(string &);

int main()
{
    string std;
    while(1)
    {
        cout << "문자열을 입력하시오. (끝내려면 q) : ";
        getline(cin,std);
        if(std == "q")
            break;
        get_to_up(std);
        cout << std << endl;
    }
    cout << "프로그램을 종료합니다.";
    return 0;
}

void get_to_up(string &std)
{
    for(int i = 0;std[i] != '\0';i++)
    {
        std[i] = toupper(std[i]);
    }
}
