#include "../header/vect1.h"
#include <cstdlib>
#include <ctime>
#include <fstream>

int main()
{
    using namespace std;
    using VECTOR::Vector;
    ofstream fout("output.txt");
    if(!fout.is_open())
    {
        cout << "파일을 열 수 없습니다.";
        exit(1);
    }
    
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
            
        fout << "목표 거리 : " << target << ", 보폭 : " << dstep << endl;
        
        while(result.magval() < target)
        {
            fout << steps << ": (x,y) = (" << result.xval() << ", " << result.yval() << ")\n";
            direction = rand() % 360;
            step.reset(dstep,direction,'p');
            result = result + step;
            steps++;
        }
        fout << steps << "걸음을 걸은 후 술고래의 위치:\n";
        fout << steps << "(x,y) = (" << result.xval() << ", " << result.yval() << ")\n";
        fout << " 또는\n";
        fout << "(m,a) = (" << result.magval() << ", " << result.angval() << ")\n";
        fout << "걸음당 기둥에서 벗어난 평균 거리 = ";
        fout << result.magval()/steps << endl;
        result.reset(0.0,0.0);
        steps = 0;
        cout << "목표 거리를 입력하십시오.(q를 입력하면 종료) : ";
    }
    cout << "프로그램을 종료합니다.";
    fout.close();
    return 0;
}
