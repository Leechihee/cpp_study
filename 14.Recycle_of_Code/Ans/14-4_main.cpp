#include <iostream>
#include <cstring>
#include <cctype>
#include "../header/person.h"
const int size = 10;
void Newlinedelete();

namespace
{
    using namespace std;
}

int main()
{
    Person * space[size];
    
    int ct;
    for(ct = 0;ct<size;ct++)
    {
        char choice;
        cout << "A. Gunslinger / B. PokerPlayer / C. BadDude / Q. Exit\n";
        cout << "직종을 선택하시오 : ";
        cin >> choice;
        while(strchr("ABCQ",toupper(choice)) == NULL)
        {
            cout << "A, B, C 중에서 하나를 입력하시오 : ";
            cin >> choice;
        }
        if(toupper(choice) == 'Q')
        {
            cout << "입력을 종료합니다.\n";
            break;
        }
        Newlinedelete();
        switch(toupper(choice))
        {
            case 'A':
                space[ct] = new Gunslinger;
                break;
            case 'B':
                space[ct] = new PokerPlayer;
                break;
            case 'C':
                space[ct] = new BadDude;
                break;
        }
        space[ct]->set();
    }
    
    cout << "SPACE INFOR\n\n";
    for(int i = 0;i<ct;i++)
        {
            space[i]->Show();
            cout << endl;
        }
    for(int i = 0;i<ct;i++)
        delete space[i];
    return 0;
}

void Newlinedelete()
{
    while(cin.get() != '\n')
        continue;
}
