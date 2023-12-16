#include <iostream>

using namespace std;

const int size = 5;

template <typename T>
T max5(T * array);

int main()
{
    int intArray[size] = {10,200,30,500,1010};
    double dobArray[size] = {1.1,20.2,11.3,11.4,5.5};
    
    cout << max5(intArray) << endl;
    cout << max5(dobArray) << endl;
    return 0;
}

template <typename T>
T max5(T * array)
{
    T maximum = 0;
    for(int i = 0;i<size;i++)
        maximum = maximum>array[i]?maximum:array[i];
    return maximum;
}
