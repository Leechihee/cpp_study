#include <iostream>

using namespace std;

int main()
{
    cout << "초 수를 입력하시오 : ";
    long time_display;
    cin >> time_display;
    const int day = 24, hour = 60, min = 60;
    int out_day, out_hour, out_min, achive;
    out_day = time_display / (day*hour*min); achive = time_display % (day*hour*min);
    out_hour = achive / (hour*min); achive = achive % (hour*min);
    out_min = achive / min; achive = achive%min;
    
    cout << time_display << "초 = " << out_day << "일,"
    << out_hour << "시간, " << out_min << "분, " << achive << "초";
    return 0;
}
