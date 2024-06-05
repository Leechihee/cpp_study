#include <iostream>
#include "../header/golf.h"

namespace
{
    using std::cout;
    using std::cin;
    using std::endl;
    int size = 10;
    int Len = 40;
}

int main()
{
    cout << "골퍼1님이 골프를 시작합니다.\n";
    golf golffer[size] = {golf("Lee", 0), golf()};
    int i,ct = 1,num,num2,ct2=1;
    char ans;
    for(i=1;i<size;i++)
    {
        char ans;
        golffer[i].setgolf();
        ct++;
        cout << "입력을 계속 하시겠습니까? (y/n) : ";
        while(!(cin>>ans) || (ans != 'Y' && ans != 'y' && ans != 'N' && ans != 'n'))
        {
            cin.clear();
            while(cin.get() != '\n')
                continue;
            cout << "y/n 중 하나를 입력하시오 . : ";
        }
        if(ans == 'N' || ans == 'n')
        {
            cout << "입력을 종료합니다.\n";
            break;
        }
        while(1)
        {
            cin.clear();
            while(cin.get() != '\n')
                continue;
            break;
        }
    }
    cout << "입력하신 골퍼들의 정보를 출력합니다.\n";
    for(i=0;i<ct;i++)
    {
        cout << "Golffer" << i+1 << " : ";
        golffer[i].showgolf();
    }
    do
    {
        ans = 'a';
        cout << ct2 <<"번째 골프를 시작합니다.\n";
        for(int k = 0;k<10;k++)
            cout << endl;
        cout << ct2 << "번째 골프가 끝났습니다.\n";
        cout << "계속 하시겠습니까? (y/n) : ";
        while(!(cin>>ans) || (ans != 'Y' && ans != 'y' && ans != 'N' && ans != 'n'))
        {
            cin.clear();
            while(cin.get() != '\n')
                continue;
            cout << "y/n 중 하나를 입력하시오 . : ";
        }
        if(ans == 'N' || ans == 'n')
        {
            cout << "골프를 종료합니다.\n";
            break;
        }
        cout << "입력하신 골퍼들의 정보를 출력합니다.\n";
        for(i=0;i<ct;i++)
        {
            cout << "Golffer" << i+1 << " : ";
            golffer[i].showgolf();
        }
        cout << "핸디캡을 수정할 골퍼의 번호와 핸디캡를 입력하세요. (문자입력시 입력종료) : ";
        while(cin>>num>>num2)
        {
            golffer[num-1].handicap(num2);
            cout << "Golffer "; golffer[num-1].showgolf();
            cout << "핸디캡을 수정할 골퍼의 번호와 핸디캡를 입력하세요. (문자입력시 입력종료) : ";
        }
        cout << "핸디캡 수정 후 골퍼들의 정보를 출력합니다.\n";
        for(i=0;i<ct;i++)
        {
            cout << "Golffer" << i+1 << " : ";
            golffer[i].showgolf();
        }
        ct2++;
        while(1)
        {
            cin.clear();
            while(cin.get() != '\n')
                continue;
            break;
        }
    }while(1);
    return 0;
}
