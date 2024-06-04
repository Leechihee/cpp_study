#include <iostream>
#include <string>

using namespace std;

int main()
{
    struct car
    {
        string comp;
        int made_year;
    };
    int input_num;
    cout << "몇 대의 차를 목록으로 관리하시겠습니까? : ";
    cin >> input_num;
    cin.get();
    car* pc = new car[input_num];
    for(int i=0;i<input_num;i++)
    {
        cout << "해당 차량의 제조업체를 입력하시오. : ";
        getline(cin,pc[i].comp);
        cout << "해당 차량의 제조년도를 입력하시오. : ";
        cin >> pc[i].made_year;
        cin.get();
    }
    cout << "현재 귀하가 보유하고 있는 차량 목록은 다음과 같습니다.\n";
    for(int i=0;i<input_num;i++)
    {
        cout << pc[i].made_year << "년형 " << pc[i].comp << endl;
    }
    delete [] pc;
    return 0;
}
