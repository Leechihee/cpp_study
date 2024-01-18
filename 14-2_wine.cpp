#include "wine.h"
#include <iostream>

namespace
{
    using std::string;
    using namespace std;
}

Wine::Wine(const char * la,int y,int ys[],int bot[]) : string(la), years(y), PairArray(ArrayInt(ys,y),ArrayInt(bot,y)) {}

Wine::Wine(const char * la, int y) : string(la), years(y), PairArray(ArrayInt(y),ArrayInt(y)) {}

void Wine::GetBottles()
{
    for(int i = 0;i<years;i++)
    {
        cout << "년도를 입력하시오: ";
        while(!(cin>>PairArray::first()[i]))
        {
            cin.clear();
            while(cin.get() != '\n')
                continue;
            cout << "숫자를 입력하시오: ";
        }
        cout << "수량을 입력하시오: ";
        while(!(cin>>PairArray::second()[i]))
        {
            cin.clear();
            while(cin.get() != '\n')
                continue;
            cout << "숫자를 입력하시오: ";
        }
    }
}

void Wine::Show() const
{
    cout << "와인 : " << Label() << endl;
    cout << "\t년도\t수량\n";
    for(int i = 0;i<years;i++)
        { 
            cout << "\t"; 
            cout << PairArray::first()[i]; 
            cout << "\t"; 
            cout << PairArray::second()[i]; 
            cout << endl;
        }
}
