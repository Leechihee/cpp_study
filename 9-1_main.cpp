#include <iostream>
#include "golf.h"

namespace
{
    int size = 10;
    using std::cout;
    using std::cin;
    using std::endl;
}
int main()
{
    golf golffer[size];
    setgolf(golffer[0],"Lee",0);
    int i,num,num2, ct = 1;
    char ans;
    cout << "골퍼1님이 골프를 시작합니다.\n";
    cout << "다른 골퍼의 정보와 핸디캡을 입력하세요.\n";
    for(i = 1;i<size;i++)
    {
        cout << i+1 << "번째 골퍼의 정보를 입력하세요.\n";
        if(!(setgolf(golffer[i])))
                break;
    }
    cout << "입력하신 골퍼들의 정보를 출력합니다.\n";
    for(int j = 0;j<i;j++)
        {
            cout << "Golffer" << j+1 << ": ";
            showgolf(golffer[j]);
        }
    do
    {
        ans = 'a';
        cout << ct <<"번째 골프를 시작합니다.\n";
        for(int k = 0;k<10;k++)
            cout << endl;
        cout << ct << "번째 골프가 끝났습니다.\n";
        cout << "계속 하시겠습니까? (y/n) : ";
        cin>>ans; 
        while(ans != 'y' && ans != 'Y' && ans != 'N' && ans != 'n')
        {
            cin.clear();
            while(cin.get() != '\n')
                continue;
            cout << "y/n중 하나를 입력하세요. : ";
            cin>>ans;
        }
        if(ans == 'N' || ans == 'n')
            break;
        cout << "입력하신 골퍼들의 정보를 출력합니다.\n";
        for(int j = 0;j<i;j++)
        {
            cout << "Golffer" << j+1 << ": ";
            showgolf(golffer[j]);
        }
        cout << "핸디캡을 수정할 골퍼의 번호와 핸디캡를 입력하세요. (문자입력시 입력종료) : ";
        while(cin>>num>>num2)
        {
            handicap(golffer[num-1],num2);
            cout << "Golffer "; showgolf(golffer[num-1]);
            cout << "핸디캡을 수정할 골퍼의 번호와 핸디캡를 입력하세요. (문자입력시 입력종료) : ";
        }
        cout << "핸디캡 수정 후 골퍼들의 정보를 출력합니다.\n";
        for(int j = 0;j<i;j++)
        {
            cout << "Golffer" << j+1 << ": ";
            showgolf(golffer[j]);
        }
        
        ct++;
    }while(ans == 'y' || ans == 'Y');
    cout << "골프를 종료합니다.";
    return 0;
}
