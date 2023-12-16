#include <iostream>

using namespace std;


template <typename T>
T maxn(T * array,int n);

int main()
{
    int intArray[6] = {10,200,30,500,1010,1111};
    double dobArray[4] = {1.1,20.2,11.3,11.4};
    char * pcArray[4] = {"asd", "asdasd", "as", "dasdas"};
    
    cout << maxn(intArray,6) << endl;
    cout << maxn(dobArray,4) << endl;
    cout << maxn(pcArray,4) << endl;
    return 0;
}

template <typename T>
T maxn(T * array, int n)
{
    T maximum = 0;
    for(int i = 0;i<n;i++)
        maximum = maximum>array[i]?maximum:array[i];
    return maximum;
}

char * maxn(char * str,int n)
{
    int ct_temp[n+1] = {0};
    char* ret_pc;
    for(int i = 0;i<n;i++)
    {
        int ct = 0;
        char* temp = &str[i];
        for(int j = 0;temp[j] != '\0';j++)
            ct++;
        ct_temp[i] = ct;
    }
    for(int i = 0;i<n;i++)
        {
            if(ct_temp[n+1] >= ct_temp[i])
                continue;
            else
                ret_pc = &str[i];
        }
    return ret_pc;
}
