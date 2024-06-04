#include <iostream>
#include <list>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>

const int SIZE = 10;

template<typename T>
int reduce(T ar[], int n);

template<typename T>
void out(T n);

int main()
{
    using namespace std;
    srand(time(0));
    long arr[SIZE];
    string strtemp[SIZE];
    string strarr[SIZE];
    ifstream filein;
    int i = 0;
    filein.open("word.txt");
    
    while(filein >> strtemp[i])
        i++;
    
    for(int i = 0;i<SIZE;i++)
    {
        arr[i] = rand() % SIZE;
        strarr[i] = strtemp[rand() % SIZE];
    }
    
    cout << "reduce() 함수 호출 전\nlong : ";
    for_each(arr,arr+SIZE,out<long>);
    cout << endl << "string : ";
    for_each(strarr,strarr+SIZE,out<string>);
    cout << endl;
    
    int count = reduce(arr,SIZE);
    int str_count = reduce(strarr,SIZE);
    
    cout << "reduce() 함수 호출 후\nlong : ";
    for_each(arr,arr+count,out<long>);
    cout << endl << "string : ";
    for_each(strarr,strarr+str_count,out<string>);
    cout << endl;
    
    cout << "종료!";
    filein.close();
    return 0;
}

template<typename T>
int reduce(T ar[], int n)
{
    std::list<T> temp(ar,ar+n);
    temp.sort();
    temp.unique();
    copy(temp.begin(),temp.end(),ar);
    return temp.size();
}

template<typename T>
void out(T n)
{
    std::cout << n << " ";
}
