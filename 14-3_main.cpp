#include "worker.h"
#include "queuetp.h"
#include <cctype>

namespace
{
    using namespace std;
}

int main()
{
    QueueTP<Worker&>(10);
    char ans;
    cout << "모 회사의 사원 정보DB 프로그램" << endl;
    do
    {
        cout << "A. 사원정보입력\tB. 사원정보제거\nC.사원정보출력\tD.프로그램종료\n";
        cin>>ans;
        switch(toupper(ans))
        {
             
        }
    }
    while(toupper(ans) != 'D');
    return 0;
}
