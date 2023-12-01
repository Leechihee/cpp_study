#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout << "출력할 행 수를 입력하시오. : ";
    int num;
    cin >> num;
    for(int i = 0;i<num;i++)
    {
        for(int j=0;j<num-i-1;j++)
        {
            cout << ".";
        }
        for(int j =0;j<=i;j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}
