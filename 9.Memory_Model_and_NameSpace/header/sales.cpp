#include <iostream>
#include <cfloat>
#include "sales.h"

namespace
{
    using namespace std;
}

namespace SALES
{
    void setSales(Sales &s, const double ar[], int n)
    {
        int count = QUARTERS<n?n:QUARTERS;
        double total = 0; 
        for(int i = 0;i<count;i++)
        {
            s.sales[i] = ar[i];
            total += ar[i];
        }
        s.average = total/count;
        s.max = DBL_MIN;
        s.min = DBL_MAX;
        for(int i = 0;i<count;i++)
        {
            s.max = s.sales[i]<s.max ? s.max:s.sales[i];
            s.min = s.sales[i]<s.min ? s.sales[i]:s.min;
        }
    }

    void setSales(Sales &s)
    {
        double total = 0;
        cout << "분기별 판매액 자료를 입력합니다.\n";
        for(int i = 0;i<4;i++)
        {
            cout << i+1 << "분기 판매액을 입력하세요. : ";
            while(!(cin>>s.sales[i]))
            {
                cin.clear();
                while(cin.get() != '\n')
                    continue;
                cout << "숫자를 입력하세요. : ";
            }
            total += s.sales[i];
        }
        s.average = total/4;
        s.max = DBL_MIN;
        s.min = DBL_MAX;
        for(int i = 0;i<4;i++)
        {
            s.max = s.sales[i]<s.max ? s.max:s.sales[i];
            s.min = s.sales[i]<s.min ? s.sales[i]:s.min;
        }
    }

    void showSales(const Sales &s)
    {
        for(int i = 0;i<4;i++)
            cout << i+1 << "분기 판매액은 " << s.sales[i] << "$이며\n";
        cout << "평균값은 " << s.average << "$\n" << "최솟값은 " << s.min << "$\n" << "최댓값은 " << s.max << "$이다.\n";
    }
}
