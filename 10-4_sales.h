#include <iostream>
#include <cfloat>

namespace SALES
{
    class Sales{
        static const int QUARTERS = 4;
        double sales[QUARTERS];
        int count;
        double average;
        void set_aver()
        {
            double total = 0;
            for(int i = 0;i<count;i++)
                total+=sales[i];
            average = total/count;
        }
        double max;
        double min;
        void set_max_min()
        {
            max = DBL_MIN;
            min = DBL_MAX;
            for(int i = 0;i<count;i++)
            {
                max = sales[i]<max ? max:sales[i];
                min = sales[i]<min ? sales[i]:min;
            }
        }
    public:
        Sales(const double ar[] = {0}, int n = 4);
        Sales setSales();
        void showSales();
    };
}
