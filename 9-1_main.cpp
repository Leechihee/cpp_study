#include <iostream>
#include "golf.h"

namespace
{
    int size = 10;
}

int main()
{
    using std::cout;
    using std::endl;
    golf pg[size];
    pg[0] = {"Lee", 0};
    cout << pg[0].fullname << "님이 골프를 시작합니다.\n";
    setgolf(pg[0],pg[0].fullname,pg[0].handicap);
    for(int i = 1;i<size;i++)
        {
            cout << i << "번째 골퍼의 정보를 입력하시오.\n";
            if(setgolf(pg[i]))
                continue;
            else
            {
                cout << "입력오류! 골퍼 입력을 종료합니다!.\n";
                break;
            }
        }
    cout << "골프를 시작하기 전에 골퍼들의 정보를 출력합니다.\n";
    for(int i = 0;i<size;i++)
    {
        cout << "Golffer " << "1" << endl;
        showgolf(pg[i]);
    }
    cout << "골프를 시작합니다!.";
    return 0;
}
