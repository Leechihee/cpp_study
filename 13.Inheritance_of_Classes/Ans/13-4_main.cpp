#include "../header/port.h"
#include <cctype>
#include <cstring>

void deleteNewline();
char * allupper(char *);

int main()
{
    Port * pp[2];
    char in_brand[50];
    char in_style[20];
    char in_nickname[50];
    int in_bottles,in_year;
    char ans;
    for(int i = 0;i<2;i++)
    {
        cout << i+1 << "번째 와인의 정보를 입력하시오.\n와인 브랜드를 입력하시오 : ";
        cin.getline(in_brand,50);
        cout << "스타일을 입력하시오 : ";
        cin.getline(in_style,20);
        cout << "와인의 재고를 입력하시오 : ";
        while(!(cin>>in_bottles))
        {
            cin.clear();
            while(cin.get() != '\n')
                continue;
            cout << "숫자를 입력하시오 : ";
        }
        deleteNewline();
        allupper(in_style);
        if(!strcmp(in_style,"VINTAGE"))
        {
            cout << "스타일이 Vintage입니다. 추가 정보를 입력하시오.\n";
            cout << "별명을 입력하시오 : ";
            cin.getline(in_nickname,50);
            cout << "년도를 입력하시오 : ";
            cin >> in_year;
            deleteNewline();
            pp[i] = new VintagePort(in_brand,in_bottles,in_nickname,in_year);
        }
        else
        {
            pp[i] = new Port(in_brand,in_style,in_bottles);
        }
    }
    cout << "와인 관리 프로그램\n";
    while(ans != 'q' && ans != 'Q')
    {
        cout << "1. 와인 재고 약식 보고 / 2. 와인 재고 정식 보고\n";
        cout << "3. 와인 입고 / 4. 와인 출고 / q. 프로그램 종료\n";
        cin >> ans;
        switch (ans)
        {
            case '1':
                for(int i = 0;i<2;i++)
                    cout << *pp[i] << endl;
                continue;
            case '2':
                for(int i = 0;i<2;i++)
                {
                    pp[i]->Show();
                    cout << endl;
                }
                continue;
            case '3':
                cout << "입고된 와인의 자리번호와 수량을 입력하시오 : ";
                cin>>in_bottles >> in_year;
                *pp[in_bottles-1] += in_year;
                continue;
            case '4':
                cout << "출고된 와인의 자리번호와 수량을 입력하시오 : ";
                cin >> in_bottles >> in_year;
                *pp[in_bottles-1] -= in_year;
                continue;
            default:
                continue;
        }
    }
    for(int i = 0;i<2;i++)
        delete pp[i];
    cout << "프로그램 종료";
    return 0;
}

void deleteNewline()
{
    while(cin.get() != '\n')
        continue;
}

char * allupper(char * str)
{
    char * restr = str;
    for(int i = 0;str[i] != '\0';i++)
        restr[i] = toupper(str[i]);
    return restr;
}
