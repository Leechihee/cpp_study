#include <iostream>
#include <array>

const int size = 10;

using namespace std;

int main()
{
    cout << "기부금을 입력하시오. (숫자 외의 문자를 입력하면 프로그램이 종료)\n";
    array<double,size> donation;
    for(int i=1;i<size;i++)
    {
        cout << i << "번째 기부금을 입력하시오. : ";
        if(!(cin >> donation[i]))
            break;
        else
        {
            
        }
    }
    return 0;
}
