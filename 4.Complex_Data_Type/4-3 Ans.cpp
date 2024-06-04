#include <iostream>
#include <cstring>

using namespace std;

char* input_firstname(void);
char* input_lastname(void);

int main()
{
    char* firstname = input_firstname();
    char* lastname = input_lastname();
    cout << "하나의 문자열로 만들면 " << lastname << ',' << firstname;
    delete [] firstname;
    delete [] lastname;
    return 0;
}

char* input_firstname(void)
{
    cout << "당신의 영문 이름을 입력하시오. : ";
    char name[80];
    cin.getline(name, 80);
    char* output = new char (strlen(name)+1);
    strcpy(output,name);
    return output;
}

char* input_lastname(void)
{
    cout << "당신의 영문 성을 입력하시오. : ";
    char name[80];
    cin.getline(name, 80);
    char* output = new char (strlen(name)+1);
    strcpy(output,name);
    return output;
}
