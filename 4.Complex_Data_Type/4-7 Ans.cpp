#include <iostream>
#include <string>

using namespace std;

int main()
{
    struct Pizza_Shop
    {
        string Pizza_Name;
        int Pizza_Radian;
        int Pizza_Waight;
    };
    
    Pizza_Shop pizza;
    
    cout << "피자 브렌드를 입력하시오. : ";
    getline(cin,pizza.Pizza_Name);
    cout << "피자의 지름을 입력하시오 : ";
    cin >> pizza.Pizza_Radian;
    cout << "피자의 중량을 입력하시오 : ";
    cin >> pizza.Pizza_Waight;
    
    cout << pizza.Pizza_Name << " 사의 피자는 "
    << pizza.Pizza_Radian << "Cm의 지름을 가지고 있고\n "
    << pizza.Pizza_Waight << "g의 중량을 가지고 있다.";
    return 0;
}
