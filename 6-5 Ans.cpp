#include <iostream>

const double one_level = 0;
const double two_level = 0.1;
const double three_level = 0.15;
const double last_level = 0.2;
using namespace std;

int main()
{
    double tvap;
    cout << "소득세 계산기\n";
    cout << "0~5000트바프는 0%, 5001~15000트바프는 10%\n"
    << "15001~35000트바프는 15%, 35001~ 바프는 20%\n";
    cout << "소득을 입력하시오. (음수나 수가 아닌 것을 입력하면 종료) : ";
    while(cin>>tvap)
    {
        if(tvap<0)
            break;
        if(tvap <= 5000)
            {
                tvap = tvap*one_level;
                cout << tvap << "트바프를 세금으로 내야한다.\n";
                cout << "소득을 입력하시오. (음수나 수가 아닌 것을 입력하면 종료) : ";
                continue;
            }
        else if(tvap > 5000 && tvap <= 15000)
            {
                tvap = 5000*one_level + (tvap-5000)*two_level;
                cout << tvap << "트바프를 세금으로 내야한다.\n";
                cout << "소득을 입력하시오. (음수나 수가 아닌 것을 입력하면 종료) : ";
                continue;
            }
        else if(tvap>15000 && tvap <= 35000)
            {
                tvap = 5000*one_level + 10000 * two_level + (tvap-15000)*three_level;
                cout << tvap << "트바프를 세금으로 내야한다.\n";
                cout << "소득을 입력하시오. (음수나 수가 아닌 것을 입력하면 종료) : ";
                continue;
            }
        else
            {
                tvap = 5000*one_level + 10000*two_level + 20000*three_level + (tvap-35000)*last_level;
                cout << tvap << "트바프를 세금으로 내야한다.\n";
                cout << "소득을 입력하시오. (음수나 수가 아닌 것을 입력하면 종료) : ";
                continue;
            }
    }
    cout << "종료";
    return 0;
}
