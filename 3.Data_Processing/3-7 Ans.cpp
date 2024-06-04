#include <iostream>

using namespace std;

int main()
{
    cout << "휘발유 소비량을 유럽스타일로 입력하시오 : ";
    float eu_sty;
    cin >> eu_sty;
    const float usa_gas = 3.875, usa_meter = 62.14;
    
    cout << "휘발유 소비량을 유럽스타일에서 미국스타일로 바꾸면 약 "
    << int (usa_meter / (eu_sty / usa_gas)) << "이다.";
    return 0;
}
