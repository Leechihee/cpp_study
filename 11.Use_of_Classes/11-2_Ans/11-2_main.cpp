#include "vect2.h"
#include <cstdlib>
#include <ctime>

int main()
{
    using namespace std;
    using VECTOR::Vector;
    
    srand(time(0));
    double direction;
    Vector step;
    Vector result(0.0,0.0);
    unsigned long steps = 0;
    double target;
    double dstep;
    cout << "목표 거리를 입력하십시오.(q를 입력하면 종료) : ";
    while(cin >> target)
    {
        cout << "보폭을 입력하십시오 : ";
        if(!(cin>>dstep))
            break;
        
        while(result.magval() < target)
        {
            cout << steps << ": (x,y) = (" << result.xval() << ", " << result.yval() << ")\n";
            direction = rand() % 360;
            step.reset(dstep,direction,'p');
            result = result + step;
            steps++;
        }
        cout << steps << "걸음을 걸은 후 술고래의 위치:\n";
        cout << steps << ": " << "(x,y) = (" << result.xval() << ", " << result.yval() << ")\n";
        cout << " 또는\n";
        cout << "(m,a) = (" << result.magval() << ", " << result.angval() << ")\n";
        cout << "걸음당 기둥에서 벗어난 평균 거리 = ";
        cout << result.magval()/steps << endl;
        result.reset(0.0,0.0);
        steps = 0;
        cout << "목표 거리를 입력하십시오.(q를 입력하면 종료) : ";
    }
    return 0;
}
