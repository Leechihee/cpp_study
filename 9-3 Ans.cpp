#include <iostream>
#include <cstring>
#include <new>

struct chaff
{
    char dross[20];
    int slag;
};

int main()
{
    using namespace std;
    chaff buffer[512];
    char instr[80];
    int inint;
    chaff *pc = new (buffer) chaff[2];
    for(int i = 0;i<2;i++)
    {
        cout << "문자열을 입력하시오.\n";
        while(!(cin>>instr))
        {
            cin.clear();
            while(cin.get() != '\n')
                continue;
            cout << "문자열을 입력하시오.\n";
        }
        strcpy(pc[i].dross,instr);
        cout << "정수를 입력하시오. : ";
        while(!(cin>>inint))
        {
            cin.clear();
                while(cin.get() != '\n')
                    continue;
                cout << "정수를 입력하시오. : ";
        }
        pc[i].slag = inint;
    }
    cout << "입력하신 정보를 출력합니다. \n";
    for(int i = 0;i<2;i++)
    {
        cout << pc[i].dross << " " << pc[i].slag << endl;
    }
    return 0;
}
