#include "../header/worker.h"
#include "../header/queuetp.h"
#include <cctype>

void newlinedelete();
namespace
{
    using namespace std;
}

int main()
{
    QueueTP<Worker*> WorkerInforDB(10);
    Worker * temp;
    char ans;
    int int_ans, count = 0;
    cout << "모 기업의 사원 정보DB 프로그램" << endl;
    while(1)
    {
        cout << "A. 사원정보입력\tB. 사원정보제거\nC.사원정보출력\tD.사원정보수정\nQ.프로그램종료\n";
        cin>>ans;
        ans = toupper(ans);
        if(ans == 'Q')
            break;
        switch(ans)
        {
            case 'A':
                cout << "A. 웨이터 / B. 가수 / C.가수 겸 웨이터\n사원의 직종을 선택하시오: ";
                cin >> ans;
                newlinedelete();
                switch (tolower(ans))
                {
                    case 'a':
                        temp = new Waiter;
                        temp->set();
                        if(WorkerInforDB.enqueue(temp))
                        {
                            cout << "사원 정보가 정상적으로 입력되었습니다." << endl;
                            count++;
                        }
                        else
                            cout << "DB가 꽉 차있어 입력이 불가능합니다.\n";
                        break;
                    case 'b':
                        temp = new Singer;
                        temp->set();
                        if(WorkerInforDB.enqueue(temp))
                        {
                            cout << "사원 정보가 정상적으로 입력되었습니다." << endl;
                            count++;
                        }
                        else
                            cout << "DB가 꽉 차있어 입력이 불가능합니다.\n";
                        break;
                    case 'c':
                        temp = new SingingWaiter;
                        temp->set();
                        if(WorkerInforDB.enqueue(temp))
                        {
                            cout << "사원 정보가 정상적으로 입력되었습니다." << endl;
                            count++;
                        }
                        else
                            cout << "DB가 꽉 차있어 입력이 불가능합니다.\n";
                        break;
                    default:
                        cout << "비정상적인 접근입니다! 사원정보입력을 취소합니다\n";
                        break;
                }
                break;
            case 'B':
                cout << "제거할 사원정보의 번호를 입력하시오.";
                cin >> int_ans;
                if(int_ans <= count && WorkerInforDB.dequeue(int_ans,temp))
                {
                    cout << "정상적으로 사원정보가 제거되었습니다.\n";
                    delete temp;
                    count--;
                }
                else
                    cout << "비정상적인 접근입니다! 사원정보제거을 취소합니다!\n";
                break;
            case 'C':
                cout << "사원정보 출력 방식을 입력하시오(전체 T/부분 U): ";
                cin >> ans;
                switch (tolower(ans))
                {
                    case 't':
                        cout << "\t모 기업의 사원 정보\n";
                        for(int i = 1;i<count+1;i++)
                        {
                            WorkerInforDB[i]->show();
                            cout << endl << endl;
                        }
                        break;
                    case 'u':
                        cout << "출력할 사원 정보의 번호를 입력하시오: ";
                        cin >> int_ans;
                        if(int_ans <= count)
                        {
                            WorkerInforDB[int_ans]->show();
                            cout << endl;
                        }
                        else
                            cout << "비정상적인 접근입니다! 사원정보출력을 취소합니다!\n";
                        break;
                    default:
                        cout << "비정상적인 접근입니다! 사원정보출력을 취소합니다!\n";
                        break;
                }
                break;
            case 'D':
                cout << "수정할 사원 정보의 번호를 입력하시오: ";
                cin >> int_ans;
                newlinedelete();
                if(int_ans <= count)
                {
                    WorkerInforDB[int_ans]->set();
                    cout << "정상적으로 사원정보를 수정하였습니다.\n";
                }
                else
                    cout << "비정상적인 접근입니다! 사원정보수정을 취소합니다!\n";
                break;
            default:
                cout << "비정상적인 접근입니다!\n";
                break;
        }
    }
    if(!WorkerInforDB.isempty())
    {
        for(int i = 0;i<count;i++)
        {
            WorkerInforDB.dequeue(i,temp);
            delete temp;
        }
    }
    cout << "프로그램 종료";
    return 0;
}

void newlinedelete()
{
    while(cin.get() != '\n')
        continue;
}
