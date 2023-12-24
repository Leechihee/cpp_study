#include <iostream>
#include <cfloat>

namespace SALES
{
    class Sales{
        static const int QUARTERS = 4;
        double sales[QUARTERS];
        int count = 0;
        double average;
        void set_aver();
        double max;
        double min;
        void set_max_min();
    public:
        Sales(const double ar[], int n);
        Sales setSales();
        void showSales(const Sales & s);
    };
    
    void Sales::set_aver()
    {
        double total = 0;
        for(int i = 0;i<count;i++)
            total+=sales[i];
        average = total/QUARTERS;
    }
    void Sales::set_max_min()
    {
        max = DBL_MIN;
        min = DBL_MAX;
        for(int i = 0;i<count;i++)
        {
            max = sales[i]<max ? max:sales[i];
            min = sales[i]<min ? sales[i]:min;
        }
    }
}
