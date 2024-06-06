#include "stonewt2.h"
#include <cfloat>

namespace
{
    int size = 6;
}

int main()
{
    using namespace std;
    Stonewt st[size] = {Stonewt(10,0.5), Stonewt(10), Stonewt(9.5)};
    Stonewt op(11,0);
    Stonewt max(DBL_MIN);
    Stonewt min(DBL_MAX);
    double n;
    int ct = 0,max_index,min_index;
    for(int i = 3;i<size;i++)
    {
        cout << i << "번째 인덱스에 넣을 무게를 입력하시오. : ";
        while(!(cin>>n))
        {
            cin.clear();
            while(cin.get() != '\n')
                continue;
            cout << "실수를 입력하시오. : ";
        }
        st[i] = Stonewt(n);
        if(st[i] > max)
        {
            max = st[i];
            max_index = i;
        }
        if(st[i] < min)
        {
            min = st[i];
            min_index = i;
        }
        if(st[i] > op)
            ct++;
    }
    cout << "최대 원소 st[" << max_index << "] = " << max << endl;
    cout << "최소 원소 st[" << min_index << "] = " << min << endl;
    cout << "11스톤보다 크거나 같은 원소의 개수는 " << ct << "개이다." << endl;
    return 0;
}
