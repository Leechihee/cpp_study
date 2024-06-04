#include <iostream>

using namespace std;

int main()
{
    cout << "두 수를 입력하는데 작은 수부터 입력하시오. : ";
    int first_input, two_input;
    cin >> first_input;
    cout <<  "나머지 한 수를 입력하시오. : ";
    cin >> two_input;
    int temp = 0;
    int i,j;
    
    for(i = first_input,j = two_input;i <= j;i++)
    {
        temp += i; 
    }
    cout << first_input << "와 " << two_input << "사이의 수의 합은\n"
    << temp << "이다.";
    
    return 0;
}
