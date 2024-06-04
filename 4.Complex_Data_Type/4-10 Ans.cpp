#include <iostream>
#include <array>

using namespace std;

int main()
{
    array <float,4> score;
    
    cout << "첫번째 40M 달리기 기록을 입력하시오. : ";
    cin >> score[0];
    cout << "두번째 40M 달리기 기록을 입력하시오. : ";
    cin >> score[1];
    cout << "세번째 40M 달리기 기록을 입력하시오. : ";
    cin >> score[2];
    
    score[4] = (score[0]+score[2]+score[1])/3;
    
    cout << "첫번째 기록은 " << score[0] << "초이며\n"
    << "두번째 기록은 " << score[1] << "초이며\n"
    << "세번째 기록은 " << score[2] << "초이다.\n"
    << "세 기록의 평균을 구하면 " << score[4] << "초이다.";
    
    return 0;
}
