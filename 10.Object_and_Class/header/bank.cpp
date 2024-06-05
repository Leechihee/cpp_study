#include <iostream>
#include "bank.h"

namespace
{
    using std::cout;
    using std::cin;
    using std::endl;
    using std::string;
}

bank::bank()
{
    Bname = "no name";
    Baccount = "aabbccdd";
    Bmoney = 0;
}

bank::bank(const string name, const string account, unsigned long n)
{
    Bname = name;
    Baccount = account;
    if(n<0)
    {
        cout << "돈은 음수가 될 수 없으므로 0$로 설정합니다.\n";
        Bmoney = 0;
    }
    else
        Bmoney = n;
}

bank::~bank()
{
    
}

void bank::show() const
{
    cout << "예금주명 : " << Bname << endl;
    cout << "계좌번호 : " << Baccount << endl;
    cout << "예금액수 : " << Bmoney << "$" << endl;
}

void bank::inMoney(const unsigned long n)
{
    cout << "입금할 계좌번호가 " << Baccount << " 맞습니까? (y/n)"  << endl;
    char ans;
    while(!(cin>>ans) || (ans != 'Y' && ans != 'y' && ans != 'N' && ans != 'n'))
    {
        cin.clear();
        while(cin.get() != '\n')
            continue;
        cout << "y/n 중 하나를 입력하시오 . : ";
    }
    if(ans != 'Y' || ans != 'y')
    {
        cout << Bname << "님의 계좌에 " << n << "$ 입금합니다.\n";
        Bmoney += n;
    }
    else
        cout << "입금을 취소합니다.\n";
}

void bank::outMoney(unsigned long n)
{
    cout << "출금할 계좌번호가 " << Baccount << " 맞습니까? (y/n)\n"  << endl;
    char ans;
    while(!(cin>>ans) || (ans != 'Y' && ans != 'y' && ans != 'N' && ans != 'n'))
    {
        cin.clear();
        while(cin.get() != '\n')
            continue;
        cout << "y/n 중 하나를 입력하시오 . : ";
    }
    if(ans != 'Y' || ans != 'y')
    {
        if(Bmoney < n)
            cout << "금액이 부족합니다. 출금을 취소합니다.\n";
        else
        {
            cout << Bname << "님 계좌에서 " << n << "$ 출금합니다.\n";
            Bmoney -= n;
        }
    }
    else
        cout << "입금을 취소합니다.\n";
}
