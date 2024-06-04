#include <iostream>
#include <string>

using namespace std;

int main()
{
    struct CandyBar
    {
        string name;
        float waight;
        int kr;
    };
    
    CandyBar snack = {"Mocha Munch", 2.3, 350};
    
    cout << "이 과자의 이름은 " << snack.name << "이고\n"
    << "중량은 " << snack.waight << "g이며\n"
    << "열량은 " << snack.kr << "칼로리이다.";
    return 0;
}
