#include <iostream>

using namespace std;

template <typename T>
T sumArray(T arr[], int n);

template <typename T>
T sumArray(T * arr[], int n);

struct debts
{
    char name[50];
    double amount;
};

int main()
{
    int things[6] = {13,31,103,301,310,130};
    struct debts mr_E[3] =
    {
        {"Ima Wolfe", 2400.0},
        {"Ura Foxe", 1300.0},
        {"Iby Stout", 1800.0}
    };
    
    double * pd[3];
    
    for(int i = 0;i<3;i++)
        pd[i] = &mr_E[i].amount;
    cout << "Mr. E의 재산의 개수와 합\n";
    cout << sizeof(things)/4 << "개 " << sumArray(things,6) << "$" << endl;
    cout << "Mr. E의 채무의 개수와 합\n";
    cout << sizeof(pd)/8 << "개 " << sumArray(pd,3)<< "$";
    return 0;
}

template <typename T>
T sumArray(T arr[], int n)
{
    T temp = 0;
    for(int i=0;i<n;i++)
        temp += arr[i];
    return temp;
}

template <typename T>
T sumArray(T * arr[], int n)
{
    T temp;
    for(int i = 0;i<n;i++)
        temp += *arr[i];
    return temp;
}
