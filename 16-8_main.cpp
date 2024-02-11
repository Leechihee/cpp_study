#include <iostream>
#include <list>
#include <algorithm>
#include <string>
#include <cctype>

using namespace std;

template<typename T>
list<T> in_name();

template<typename T>
void out(T n)
{
    cout << n << " ";
}

char toLower(char ch)
{
    return tolower(ch);
}

string ToLower(string & s)
{
    transform(s.begin(),s.end(),s.begin(),toLower);
    return s;
}
int main()
{
    cout << "메트 리스트\n";
    list<string> mat(in_name<string>());
    cout << "페트 리스트\n";
    list<string> pat(in_name<string>());
    
    cout << "\n메트가 초대한 사람의 이름 목록\n";
    for_each(mat.begin(),mat.end(),out<string>);
    cout << "\n페트가 초대한 사람의 이름 목록\n";
    for_each(pat.begin(),pat.end(),out<string>);
    list<string> total;
    total.splice(total.begin(),mat);
    total.splice(total.begin(),pat);
    total.sort();
    cout << "\n메트와 패트가 초대한 사람의 이름 목록 :\n";
    total.unique();
    for_each(total.begin(),total.end(),out<string>);
}

template<typename T>
list<T> in_name()
{
    list<T> temp;
    string name;
    cout << "초대할 사람의 이름을 입력하시오 : ";
    while(getline(cin,name) && ToLower(name) != "quit")
    {
        temp.push_back(name);
        cout << "초대할 사람의 이름을 입력하시오 (종료는 quit) : ";
    }
    return temp;
}
