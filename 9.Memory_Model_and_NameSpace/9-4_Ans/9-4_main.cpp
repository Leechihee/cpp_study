#include <iostream>
#include "sales.h"

namespace
{
    using namespace std;
    using namespace SALES;
}

int main()
{
    Sales s1,s2;
    double arr[] = {10.1,12.2,13.3,21.7,9.2};
    setSales(s1,arr,5);
    setSales(s2);
    cout << "s1\n";
    showSales(s1);
    cout << "s2\n";
    showSales(s2);
    return 0;
}
