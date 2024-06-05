#include "wine1.h"
#include <cstring>
#include <iostream>

namespace
{
    using namespace std;
}

Wine::Wine() : years(0)
{
    label = new char[strlen("NULL")+1];
    strcpy(label,"NULL");
    ArrayInt year;
    ArrayInt bottles;
    wine_infor = new PairArray(year,bottles);
}

Wine::Wine(const char * la, int y, const int yt[], const int bot[]) : years(y)
{
    label = new char[strlen(la)+1];
    strcpy(label,la);
    ArrayInt year(yt,years);
    ArrayInt bottles(bot,years);
    wine_infor = new PairArray(year,bottles);
}

Wine::Wine(const char * la, int y) : years(y)
{
    label = new char[strlen(la)+1];
    ArrayInt year(years);
    ArrayInt bottles(years);
    wine_infor = new PairArray(year,bottles);
    strcpy(label,la);
}

void Wine::GetBottles()
{
    int in;
    cout << years << "년간의 " << label << " 데이터를 입력하시오:\n";
    for(int i = 0;i<years;i++)
    {
        int in;
        cout << "년도를 입력하시오: ";
        while(!(cin>>in))
        {
            cin.clear();
            while(cin.get() != '\n')
                continue;
            cout << "숫자를 입력하시오: ";
        }
        wine_infor->first()[i] = in;
        cout << "수량을 입력하시오: ";
        while(!(cin>>in))
        {
            cin.clear();
            while(cin.get() != '\n')
                continue;
            cout << "숫자를 입력하시오: ";
        }
        wine_infor->second()[i] = in;
    }
}

void Wine::Show() const
{
    cout << "와인 : " << label << endl;
    cout << "\t년도\t수량\n";
    for(int i = 0;i<years;i++)
        { 
            cout << "\t"; 
            cout<< wine_infor->first()[i]; 
            cout << "\t"; 
            cout << wine_infor->second()[i]; 
            cout << endl;
        }
}
