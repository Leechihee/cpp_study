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
        count = QUARTERS<n?n:QUARTERS;
        for(int i = 0;i<count;i++)
        {
            sales[i] = ar[i];
        }
        set_aver();
        set_max_min();
    }
}

