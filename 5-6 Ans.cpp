#include <iostream>
#include <string>

const int size = 12,y_size=3;

using namespace std;

int main()
{
    string num1[y_size][size] = 
    {
        {"1월", "2월", "3월", "4월", "5월" , "6월", "7월", "8월", "9월", "10월", "11월", "12월"},
        {"1월", "2월", "3월", "4월", "5월" , "6월", "7월", "8월", "9월", "10월", "11월", "12월"},
        {"1월", "2월", "3월", "4월", "5월" , "6월", "7월", "8월", "9월", "10월", "11월", "12월"}
        
    };
    int num2[y_size][size], temp[3] = {0}, year[y_size] = {23,24,25};
    for(int j = 0;j<y_size;j++)
        for(int i = 0;i<size;i++)
        {
            cout << year[j] << "년 " << num1[j][i] << "에 판매한 책 권수를 입력하시오. : ";
            cin >> num2[j][i];
            temp[j] += num2[j][i];
        }
    for(int i;i<y_size;i++)
        cout << year[i] << "년에 판매한 책 수는 " << temp[i] << "권이다.\n";
    return 0;
}
