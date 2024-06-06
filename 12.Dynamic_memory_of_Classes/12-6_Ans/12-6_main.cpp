#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../12-5_Ans/queue.h"

const int MIN_PER_HR = 60;
using namespace std;

bool newcustomer(double x);

int main()
{
    srand(time(0));
    cout << "사례 연구 : 히서 은행의 ATM\n";
    cout << "큐의 최대 길이를 입력하십시오 : ";
    int qs,qs2;
    cin >> qs >> qs2;
    
    cout << "시뮬레이션 시간 수를 입력하십시오 : ";
    int hours;
    cin >> hours;
    long cyclelimits = hours * MIN_PER_HR;
    
    double perhours;
    double min_per_cst;
    
    long cycle;
    
    Item temp;
    long turnaway;
    long served;
    int wait_time,wait_time2;
    long line_wait;
    double result = 0;
    
    for(perhours = 1;result < 1.0;perhours++)
    {
        Queue line(qs);
        Queue line2(qs2);
        min_per_cst = MIN_PER_HR / perhours;
        turnaway = 0;
        served = 0;
        wait_time = 0; wait_time2 = 0;
        line_wait = 0;
        for(cycle = 0;cycle<cyclelimits;cycle++)
        {
            if(newcustomer(min_per_cst))
            {
                if(line.isfull() && line2.isfull())
                    turnaway++;
                else
                {
                    temp.set(cycle);
                    if(line.queuecount() < line2.queuecount())
                        line.enqueue(temp);
                    else
                        line2.enqueue(temp);
                }
            }
            if(wait_time <= 0 && !line.isempty())
            {
                line.dequeue(temp);
                wait_time = temp.ptime();
                line_wait += cycle - temp.when();
                served++;
            }
            if(wait_time2 <= 0 && !line2.isempty())
            {
                line2.dequeue(temp);
                wait_time2 = temp.ptime();
                line_wait += cycle - temp.when();
                served++;
            }
            if(wait_time > 0)
                wait_time--;
            if(wait_time2 > 0)
                wait_time--;
        }
        result = (double)line_wait / (double)served;
    }
    cout << "평균 대기 시간이 1분일때, 시간당 평균 고객 수는 " << endl;
    cout << perhours << "명이다.";
    return 0;
}

bool newcustomer(double x)
{
    return (rand() * x / RAND_MAX < 1);
}
