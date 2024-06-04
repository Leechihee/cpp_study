#include <iostream>
#include <string>

using namespace std;

struct donation
{
    string name;
    double money;
};

int main()
{
    int num;
    cout << "기부자가 몇명인지 입력하시오 : ";
    while(!(cin>>num))
        {
            cin.clear();
            while(cin.get() != '\n')
                continue;
            cout << "숫자를 입력하시오. : ";
        }
    cin.get();
    if(num == 0)
        {
            cout << "기부자가 없습니다";
            return 0;
        }
    donation * pd = new donation[num];
    for(int i=0;i<num;i++)
    {
        cout << i+1 << "번째 후원자의 이름을 입력하시오. : ";
        getline(cin,pd[i].name);
        while(pd[i].name == "")
        {
            cout << "오류!\n";
            cout << "이름을 다시 입력하시오. : ";
            getline(cin,pd[i].name);
        }
        cout << "후원한 금액을 입력하시오. : ";
        while(!(cin>>pd[i].money))
        {
            cin.clear();
            while(cin.get() != '\n')
                continue;
            cout << "숫자를 입력하시오. : ";
        }
        cin.get();
    }
    cout << "고액 기부자\n";
    for(int i = 0;i<num;i++)
    {
        if(pd[i].money >= 10000)
            cout << pd[i].name << endl;
    }
    cout << "소액 기부자\n";
    for(int i = 0;i<num;i++)
    {
        if(pd[i].money < 10000)
            cout << pd[i].name << endl;
    }
    delete [] pd;
    return 0;
}
