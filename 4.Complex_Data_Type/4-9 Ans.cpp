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
    
    CandyBar * pcb = new CandyBar[3];
    pcb[0].name = "Moca Munch";
    pcb[0].waight = 2.3;
    pcb[0].kr = 350;
    
    pcb[1].name = "Poka Chip";
    pcb[1].waight = 10.2;
    pcb[1].kr = 450;
    
    pcb[2].name = "Choco Pie";
    pcb[2].waight = 1.1;
    pcb[2].kr = 120;
    
    cout << "첫번째 과자의 이름은 " << pcb[0].name << "이고\n"
    << "중량은 " << pcb[0].waight << "g이며\n"
    << "열량은 " << pcb[0].kr << "칼로리이다.\n\n";
    
    cout << "두번째 과자의 이름은 " << pcb[1].name << "이고\n"
    << "중량은 " << pcb[1].waight << "g이며\n"
    << "열량은 " << pcb[1].kr << "칼로리이다.\n\n";
    
    cout << "세번째 과자의 이름은 " << pcb[2].name << "이고\n"
    << "중량은 " << pcb[2].waight << "g이며\n"
    << "열량은 " << pcb[2].kr << "칼로리이다.\n\n";
    
    delete[] pcb;
    return 0;
}
