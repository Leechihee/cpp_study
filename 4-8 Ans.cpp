#include <iostream>

using namespace std;

int main()
{
    struct Pizza_Shop
    {
        char Pizza_Name[20];
        int Pizza_Radian;
        int Pizza_Waight;
    };
    
    Pizza_Shop * pps = new Pizza_Shop;
    
    cout << "피자의 지름을 입력하시오 : ";
    cin >> pps->Pizza_Radian;
    cin.get();
    cout << "피자 브렌드를 입력하시오. : ";
    cin.get(pps->Pizza_Name,20);
    cout << "피자의 중량을 입력하시오 : ";
    cin >> pps->Pizza_Waight;
    
    cout << pps->Pizza_Name << " 사의 피자는 "
    << pps->Pizza_Radian << "Cm의 지름을 가지고 있고\n "
    << pps->Pizza_Waight << "g의 중량을 가지고 있다.";
    delete pps;
    return 0;
}
