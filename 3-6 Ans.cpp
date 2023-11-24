#include <iostream>

using namespace std;

int main()
{
    cout << "주행한 마일을 입력하시오 : ";
    float mail, gallon;
    cin >> mail;
    cout << "소비한 휘발유 양을 갤런 단위로 입력하시오 : ";
    cin >> gallon;
    cout << "1갤런당 주행한 거리는 : " << mail/gallon << "이다.\n";
    
    cout << "주행한 거리를 Km단위로 입력하시오 : ";
    float km, liter;
    cin >> km;
    cout << "소비한 휘발유 양을 리터 단위로 입력하시오 : ";
    cin >> liter;
    cout << "100Km당 사용한 휘발유는 " << liter / (km/100) << "이다.";
    return 0;
}
