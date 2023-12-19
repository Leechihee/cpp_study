#include <iostream>
#include "golf.h"

using std::cout;
using std::cin;
using std::endl;

void setgolf(golf &g, const char *name, int hc)
{
    *g.fullname = *name;
    g.handicap = hc;
}

int setgolf(golf &g)
{
    cout << "이름을 입력하시오.";
    if(!(cin>>g.fullname))
    {
        cout << "입력오류!";
        return 0;
    }
    int hc;
    cout << "핸디캡을 입력하시오. :";
    while(!(cin>>g.handicap))
    {
        cin.clear();
        if(cin.get() != '\n')
            continue;
        cout << "숫자를 입력하시오. : ";
    }
    return 0;
}

void handicap(golf &g)
{
    cout << "수정할 핸디캡을 입력하시오. :";
    while(!(cin>>g.handicap))
    {
        cin.clear();
        if(cin.get() != '\n')
            continue;
        cout << "숫자를 입력하시오. : ";
    }
}

void showgolf(const golf &g)
{
    cout << g.fullname << endl;
    cout << g.handicap<< endl;
}
