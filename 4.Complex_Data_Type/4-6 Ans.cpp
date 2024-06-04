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
    
    CandyBar snack[3] = 
    {
        {"Mocha Munch", 2.3, 350},
        {"Poka Chip", 10.2, 450},
        {"Choco Pie", 1.1, 120}
    };
    
    cout << "첫번째 과자의 이름은 " << snack[0].name << "이고\n"
    << "중량은 " << snack[0].waight << "g이며\n"
    << "열량은 " << snack[0].kr << "칼로리이다.\n\n";
    
    cout << "두번째 과자의 이름은 " << snack[1].name << "이고\n"
    << "중량은 " << snack[1].waight << "g이며\n"
    << "열량은 " << snack[1].kr << "칼로리이다.\n\n";
    
    cout << "세번째 과자의 이름은 " << snack[2].name << "이고\n"
    << "중량은 " << snack[2].waight << "g이며\n"
    << "열량은 " << snack[2].kr << "칼로리이다.\n\n";
    return 0;
}
