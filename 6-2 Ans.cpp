#include <iostream>
#include <array>

const int size = 10;

using namespace std;

int main()
{
    cout << "기부금을 입력하시오. (숫자 외의 문자를 입력하면 프로그램이 종료)\n";
    array<double,size> donation;
    double temp = 0;
    int count = 0,count2 = 0;
    for(int i=0;i<size;i++)
    {
        cout << i+1 << "번째 기부금을 입력하시오. : ";
        if(!(cin >> donation[i]))
            break;
        else
        {
            temp += donation[i];
            count++;
        }
    }
    temp = temp /count;
    for(int i=0;i<count;i++)
    {
        if(donation[i] >temp)
            count2++;
    }
    cout << "기부금액의 평균은 " << temp << "원이며 \n"
    << "평균 기부금액을 넘어서는 기부금액 개수는 " << count2 << "개이다.";
    return 0;
}
