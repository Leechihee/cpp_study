#include <iostream>
#include "golf.h"

namespace
{
    using std::cout;
    using std::cin;
    using std::endl;
}

void setgolf(golf &g, const char *name, int hc)
{
    for(int i = 0;name[i] != '\0';i++)
        g.fullname[i] = name[i];
    g.handicap = hc;
}

int setgolf(golf &g)
{
    cout << "골퍼의 이름을 입력하시오. (빈칸입력시 종료) : ";
    if(!(cin.getline(g.fullname,Len)) || g.fullname[0] == '\0')
        {
            cout << "입력오류! 입력을 종료합니다.\n";
            return 0;
        }
    cout << "핸디캡을 입력하시오 : ";
    while(!(cin>>g.handicap))
    {
        cin.clear();
        while(cin.get() != '\n')
            continue;
        cout << "숫자를 입력하시오. : ";
    }
    cin.get();
    return 1;
}

void handicap(golf &g,int hc)
{
    g.handicap = hc;
}

void showgolf(const golf &g)
{
    cout << g.fullname;
    cout << " Handicap : " << g.handicap << endl;
}
