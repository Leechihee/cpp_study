#include <iostream>
#include "sales.h"

namespace
{
    using std::cout;
    using std::cin;
}
namespace SALES
{
    Sales::Sales(const double ar[], int n)
    {
        count = QUARTERS<n?QUARTERS:n;
        for(int i = 0;i<count;i++)
        {
            sales[i] = ar[i];
        }
        set_aver();
        set_max_min();
    }
    
    Sales Sales::setSales()
    {
        double arr[QUARTERS];
        int ct = 0;
        cout << "분기별 판매액 자료를 입력합니다.\n";
        for(int i = 0;i<QUARTERS;i++)
        {
            cout << i+1 << "분기 판매액을 입력하세요. (문자 입력시 입력종료) : ";
            if(!(cin>>arr[i]))
            {
                cout << "입력오류! 입력을 종료합니다.\n";
                break;
            }
            ct++;
        }
        *this = Sales(arr,ct);
        return *this;
    }
    
    void Sales::showSales()
    {
        for(int i = 0;i<count;i++)
            cout << i+1 << "분기 판매액은 " << sales[i] << "$이며\n";
        cout << "평균값은 " << average << "$\n" << "최솟값은 " << min << "$\n" << "최댓값은 " << max << "$이다.\n";
    }
}
