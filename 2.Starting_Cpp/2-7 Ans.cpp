#include <iostream>

using namespace std;

void time_set(int,int);

int main()
{
    cout << "시간 값을 입력하시오 : ";
    int hour;
    cin >> hour;
    cout << "분 값을 입력하시오 : ";
    int min;
    cin >> min;
    time_set(hour,min);
    return 0;
}

void time_set(int h,int m)
{
    cout << "시각: " << h << ":" << m;
}
