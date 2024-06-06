#include "worker.h"
#include <iostream>

namespace
{
    using std::cout;
    using std::endl;
    using std::cin;
}

//Worker protected method
void Worker::Data() const
{
    cout << "사원 이름: " << fullname << endl;
    cout << "사원 ID: " << ld << endl;
}

void Worker::Get()
{
    cout << "해당 사원의 이름을 입력하시오: ";
    getline(cin,fullname);
    cout << "해당 사원의 ID를 입력하시오: ";
    while(!(cin>>ld))
    {
        cin.clear();
        while(cin.get() != '\n')
            continue;
        cout << "숫자를 입력하시오: ";
    }
}

//Worker public method
Worker::~Worker() {}

//Waiter protected method
void Waiter::Data() const
{
    cout << "웨이터 등급: " << panache << endl;
}

void Waiter::Get()
{
    cout << "웨이터 등급을 입력하시오: ";
    while(!(cin>>panache))
    {
        cin.clear();
        while(cin.get() != '\n')
            continue;
        cout << "숫자를 입력하시오: ";
    }
}

//Waiter public method
void Waiter::set()
{
    Worker::Get();
    Get();
}

void Waiter::show() const
{
    cout << "직종 : 웨이터\n";
    Worker::Data();
    Data();
}

//Singer private method
char *Singer::pv[Singer::Vtypes] = {"other", "alto", "contralto", "soprano", "bass", "baritone", "tenor"};

//Singer protected method
void Singer::Data() const
{
    cout << "목소리 유형: " << pv[voice] << endl;
}

void Singer::Get()
{
    cout << "가수의 목소리 유형을 선택하시오: ";
    for(int i = 0;i<Singer::Vtypes;i++)
    {
        cout << pv[i] << " ";
        if(i % 4 == 0)
            cout << endl;
    }
    cout << endl;
    while(!(cin>>voice) && voice > 7)
    {
        cin.clear();
        while(cin.get() != '\n')
            continue;
        cout << "숫자를 입력하거나 7 이하의 숫자를 입력하시오: ";
    }
}

//Singer public method
void Singer::set()
{
    Worker::Get();
    Get();
}

void Singer::show() const
{
    Worker::Data();
    Data();
}

//SingingWaiter protected method
void SingingWaiter::Data() const
{
    Waiter::Data();
    Singer::Data();
}

void SingingWaiter::Get()
{
    Waiter::Get();
    Singer::Get();
}

//SingingWaiter public method
void SingingWaiter::set()
{
    Worker::Get();
    Get();
}

void SingingWaiter::show() const
{
    Worker::Data();
    Data();
}
