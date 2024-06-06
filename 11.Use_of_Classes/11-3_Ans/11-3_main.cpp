#include "../11-1_Ans/vect1.h"
#include <cstdlib>
#include <ctime>
#include <climits>

int main()
{
    using namespace std;
    using VECTOR::Vector;
    
    srand(time(0));
    double direction;
    Vector step;
    Vector result(0.0,0.0);
    unsigned long steps = 0, total_steps = 0, min = ULONG_MAX, max = 0;
    double target;
    double dstep;
    int ct;
    cout << "목표 거리를 입력하십시오.(q를 입력하면 종료) : ";
    while(cin >> target)
    {
        cout << "보폭을 입력하십시오 : ";
        if(!(cin>>dstep))
            break;
        cout << "시행할 횟수를 입력하시오 : ";
        while(!(cin>>ct))
        {
            cin.clear();
            while(cin.get() != '\n')
                continue;
            cout << "숫자를 입력하시오. : ";
        }
        for(int i = 0;i<ct;i++)
        {
            while(result.magval() < target)
            {
                direction = rand() % 360;
                step.reset(dstep,direction,'p');
                result = result + step;
                steps++;
            }
            total_steps += steps;
            if(steps < min)
                min = steps;
            else if(steps > max)
                max = steps;
            result.reset(0.0,0.0);
            steps = 0;
        }
        cout << "최고 걸음 수 : " << max << endl;
        cout << "최저 걸음 수 : " << min << endl;
        cout << "평균 걸음 수 : " << total_steps/ct << endl;
        cout << "목표 거리를 입력하십시오.(q를 입력하면 종료) : ";
    }
    return 0;
}
