#include <iostream>
#include <string>

using namespace std;

int main()
{
    struct sungjuk
    {
        char name[20];
        char sung[10];
        char score;
        int old;
    }sj;
    
    cout << "당신의 영문이름을 입력하시오 : ";
    cin.getline(sj.name,20);
    cout << "당신의 영문 성을 입력하시오 : ";
    cin >> sj.sung;
    cout << "원하는 학점을 입력하시오 : ";
    cin >> sj.score;
    cout << "나이를 입력하시오 : ";
    cin >> sj.old;
    
    cout << "성명 : " << sj.sung << ", " << sj.name << endl;
    cout << "학점 : " << char (sj.score+1) << endl;
    cout << "나이 : " << sj.old << endl;
    return 0;
}
