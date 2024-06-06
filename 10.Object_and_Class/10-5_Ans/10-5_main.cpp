#include <iostream>
#include <cctype>
#include "Stack.h"

namespace
{
    using std::cout;
    using std::cin;
}

int main()
{
    Stack st;
    char ans;
    customer cm;
    cout << "주문서를 입력하려면 A, 주문서를 처리할려면 B\n프로그램 종료는 Q을 입력하세요.\n";
    double total_payment = 0;
    while(cin>>ans && toupper(ans) != 'Q')
    {
        while(cin.get() != '\n')
            continue;
        if(!isalpha(ans))
        {
            cout << '\a';
            continue;
        }
        switch(ans)
        {
            case 'A':
            case 'a': cout << "추가할 영수증의 고객의 성함과 물품의 가격을 입력하세요.\n";
                    while(!(cin >> cm.fullname >> cm.payment))
                        {
                            cin.clear();
                            while(cin.get() != '\n')
                                continue;
                            cout << "입력오류! 다시입력하세요.";
                        }
                    if(st.isfull())
                        cout << "스택이 풀로 차있습니다.\n";
                    else{
                        st.push(cm);
                        break;
                    }
            case 'B':
            case 'b': if(st.isempty())
                        cout << "스택이 비어있습니다.\n";
                    else{
                        st.pop(cm);
                        cout << cm.fullname << "님의 물품을 계산하였습니다.\n";
                        total_payment += cm.payment;
                    }
                    break;
        }
        cout << "주문서를 입력하려면 A, 주문서를 처리할려면 B\n프로그램 종료는 Q을 입력하세요.\n";   
    }
    cout << "수익 : " << total_payment << "$\n";
    cout << "프로그램을 종료합니다.";
    return 0;
}
