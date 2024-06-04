#include <iostream>

using namespace std;
const int size = 10;

void input(int *n, int *a);
void output(int *n, int a);
int sum(int *n,int a);

int main()
{
    int score[size], ct = 0;
    input(score,&ct);
    cout << "입력하신 골프 스코어는 ";
    output(score,ct);
    cout << "이며 \n";
    cout << "평균 스코어는 " << sum(score,ct) << "입니다.\n";
    cout << "종료합니다.";
    return 0;
}

void input(int *n, int *a)
{
    for(int i = 0;i<size;i++)
    {
        cout << "골프 스코어를 입력하시오. (숫자가 아닌 것을 입력하면 입력종료, 최대 10개까지 입력가능)\n";
        if(!(cin >> n[i]))
                break;
        *a += 1;
    }
}

void output(int *n, int a)
{
    for(int i = 0;i<a;i++)
    {
        cout << n[i] << " ";
    }
}

int sum(int *n,int a)
{
    int sum = 0;
    for(int i = 0;i < a;i++)
        sum += n[i];
    return sum/a;
}
