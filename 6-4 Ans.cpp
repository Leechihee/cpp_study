#include <iostream>

const int strsize = 80;
const int size = 4;
using namespace std;

struct bop
{
    char fullname[strsize];
    char title[strsize];
    char bopname[strsize];
    int preference;
};

int main()
{
    char ch;
    bop name[size] =
    {
        {"이치희", "서버장", "Onhanabi", 0},
        {"이경환", "부서버장", "Dog", 2},
        {"김예찬", "용광로", "Pig",2},
        {"서덕현", "짬찌", "tail",1}
    };
    
    cout << "Benevolent Order of Programmers\n";
    cout << "a. 실명으로 열람       b.직함으로 열람\n"
    << "c.BOF 아이디로 열람        d.회원이 지정한 것으로 열람\n"
    << "q. 프로그램 종료\n";
    cout << "원하는 것을 입력하시오. : ";
    cin >> ch;
    while(ch != 'q')
    {
        switch (ch)
            {case 'a':
                {
                    for(int i=0;i<size;i++)
                        cout << name[i].fullname << endl;
                    cout << "원하는 것을 입력하시오. : ";
                    cin >> ch;
                    continue;
                }
            case 'b':
                {
                    for(int i=0;i<size;i++)
                        cout << name[i].title << endl;
                    cout << "원하는 것을 입력하시오. : ";
                    cin >> ch;
                    continue;
                }
            case 'c':
                {
                    for(int i=0;i<size;i++)
                        cout << name[i].bopname << endl;
                    cout << "원하는 것을 입력하시오. : ";
                    cin >> ch;
                    continue;
                }
            case 'd':
                {
                    for(int i=0;i<size;i++)
                        if(name[i].preference == 0)
                            cout << name[i].fullname << endl;
                        else if(name[i].preference == 1)
                            cout << name[i].title << endl;
                        else
                            cout << name[i].bopname << endl;
                    cout << "원하는 것을 입력하시오. : ";
                    cin >> ch;
                    continue;
                }
            default:
                {
                    cout << "다시 입력하시오. : ";
                    cin >> ch;
                    continue;
                }
            }
    }
    cout << "프로그램을 종료합니다.";
    return 0;
}
