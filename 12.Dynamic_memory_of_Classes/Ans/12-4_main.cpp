#include "../header/Stack.h"
#include <iostream>
#include <cctype>

using namespace std;

int main()
{
    Stack starr[4] = {Stack(),Stack(5),Stack(starr[1])};
    char frist_ans, ans;
    int st_cho,tar_st;
    Item input, output;
    cout << "A. 스택선택 C. 스택복사 Q.프로그램종료\n";
    while(cin>>frist_ans && toupper(frist_ans) != 'Q')
    {
        while(cin.get() != '\n')
            continue;
        if(!isalpha(frist_ans))
        {
            cout << '\a';
            continue;
        }
        switch(toupper(frist_ans))
        {
            case 'A':
                cout << "몇번 스택을 사용하시겠습니까? : ";
                while(!(cin>>st_cho))
                {
                    cin.clear();
                    while(cin.get() != '\n')
                        continue;
                    cout << "숫자를 입력하시오. : ";
                }
                cout << st_cho << "번 스택을 선택하셨습니다.\n";
                cout << "A. 정보입력 B. 정보출력 Q.입력종료 및 돌아가기.\n";
                while(cin>>ans && toupper(ans) != 'Q')
                {
                    while(cin.get() != '\n')
                        continue;
                    if(!isalpha(ans))
                    {
                        cout << '\a';
                        continue;
                    }
                    switch(toupper(ans))
                    {
                        case 'A':
                            if(starr[st_cho-1].isfull())
                            {
                                cout << "스택이 가득 차있습니다.\n";
                                break;
                            }
                            cout << "정보를 입력하시오. : ";
                            while(!(cin>>input))
                            {
                            cin.clear();
                                while(cin.get() != '\n')
                                    continue;
                                cout << "숫자를 입력하시오. : ";
                            }
                            starr[st_cho-1].push(input);
                            break;
                        case 'B':
                            if(starr[st_cho-1].isempty())
                                cout << "스택이 비어있습니다.\n";
                            else
                            {
                                starr[st_cho-1].pop(output);
                                cout << "정보 : " << output << endl;
                                break;
                            }
                        default:
                            break;
                    }
                    cout << "A. 정보입력 B. 정보출력 Q.입력종료 및 돌아가기.\n";
                }
                break;
            case 'C':
                cout << "복사할 스택번호와 대상스택 번호를 입력하시오. : ";
                while(!(cin>>st_cho>>tar_st))
                {
                    cin.clear();
                    while(cin.get() != '\n')
                        continue;
                    cout << "복사할 스택번호와 대상스택 번호를 입력하시오. : ";
                }
                starr[tar_st-1] = starr[st_cho-1];
                break;
            default:
                cout << "A. 스택선택 C. 스택복사 Q.프로그램종료\n";
                break;
        }
        cout << "A. 스택선택 C. 스택복사 Q.프로그램종료\n"; 
    }
    cout << "2번 스택을 출력스택으로 복사 후 출력!\n";
    Stack stout(starr[1]);
    for(;;)
    {
        if(stout.isempty())
        {
            cout << "스택이 비어있습니다.\n";
            break;
        }
        else
        {
            stout.pop(output);
            cout << "정보 : " << output << endl;
        }
    }
    cout << "프로그램 종료";
    return 0;
}
