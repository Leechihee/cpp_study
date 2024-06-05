#include <iostream>
#include "../header/sales.h"

int main()
{
    using namespace SALES;
    double arr[] = {11.2,12.2,123.3,14.5,15.8};
    Sales s(arr,5);
    s.showSales();
    s.setSales();
    s.showSales();
    return 0;
}
