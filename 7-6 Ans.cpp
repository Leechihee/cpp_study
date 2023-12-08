#include <iostream>

const int size = 10;
using namespace std;

int Fill_array(double *, int);
void Show_array(const double *,int);
void Reverse_array(double *,int);

int main()
{
    double numbers[size];
    int count = Fill_array(numbers,size);
    Show_array(numbers,count);
    cout << endl;
    Reverse_array(numbers,count);
    Show_array(numbers,count);
    cout << endl;
    Reverse_array(numbers+1,count-2);
    Show_array(numbers,count);
    return 0;
}

int Fill_array(double *num, int ct)
{
    int count = 0;
    for(int i = 0;i<ct;i++)
    {
        cout << i+1 << "번째 배열에 넣을 숫자를 입력하시오. (숫자가 아닌 것을 입력하면 종료) : ";
        if(!(cin>>num[i]) == 1)
            break;
        count++;
    }
    return count;
}

void Show_array(const double num[], int ct)
{
    for(int i = 0;i<ct;i++)
    {
        cout << "numbers[" << i << "] = " << num[i] << endl;
    }
}

void Reverse_array(double *num, int ct)
{
    double temp;
    int i,j;
    for(i=0,j=ct-1;i<j;i++,j--)
    {
        temp = num[i];
        num[i] = num[j];
        num[j] = temp;
    }
}
