#include <iostream>
#include <string>

const int size = 12;

using namespace std;

int main()
{
    string num1[size] = {"1월", "2월", "3월", "4월", "5월" , "6월", "7월", "8월", "9월", "10월", "11월", "12월"};
    int num2[size], temp = 0;
    
    for(int i = 0;i<size;i++)
    {
        cout << num1[i] << "에 판매한 책 권수를 입력하시오. : ";
        cin >> num2[i];
        temp += num2[i];
    }
    
    cout << "금년에 판매한 책 수는 " << temp << "권이다.";
    return 0;
}
