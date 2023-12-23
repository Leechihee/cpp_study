#include <iostream>
#include "golf.h"

namespace
{
    using std::cout;
    using std::cin;
    using std::endl;
}

golf::golf(const char *name, int hc)
{
    for(int i = 0;name[i] != '\0';i++)
        GOLF.fullname[i] = name[i];
    GOLF.handicap = hc;
}

golf golf::setgolf()
{
    char name[Len];
    int hc;
    cout << "골퍼의 이름을 입력하시오. (빈칸입력시 종료) : ";
    if(!(cin.getline(name,Len)) || name[0] == '\0')
        {
            cout << "입력오류! 입력을 종료합니다.\n";
            return *this;
        }
    cout << "핸디캡을 입력하시오 : ";
    while(!(cin>>hc))
    {
        cin.clear();
        while(cin.get() != '\n')
            continue;
        cout << "숫자를 입력하시오. : ";
    }
    *this = golf(name,hc);
    cin.get();
    return *this;
}

void golf::handicap(int hc)
{
    GOLF.handicap = hc;
}

void golf::showgolf() const
{
    cout << GOLF.fullname;
    cout << " Handicap : " << GOLF.handicap << endl;
}
