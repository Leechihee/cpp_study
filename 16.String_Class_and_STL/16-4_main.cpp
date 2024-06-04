#include <iostream>
#include <list>
#include <algorithm>
#include <cstdlib>
#include <ctime>

const int SIZE = 10;

int reduce(long ar[], int n);
void out(long n);

int main()
{
    using namespace std;
    srand(time(0));
    long arr[SIZE];
    for(int i = 0;i<SIZE;i++)
        arr[i] = rand() % 10;
    cout << "reduce() 함수 호출 전\n";
    for_each(arr,arr+SIZE,out);
    cout << endl;
    int count = reduce(arr,SIZE);
    cout << "reduce() 함수 호출 후\n";
    for_each(arr,arr+count,out);
    cout << endl;
    cout << "종료!";
    return 0;
}

int reduce(long ar[], int n)
{
    std::list<long> temp(ar,ar+n);
    temp.sort();
    temp.unique();
    copy(temp.begin(),temp.end(),ar);
    return temp.size();
}

void out(long n)
{
    std::cout << n << " ";
}
