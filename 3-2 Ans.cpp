#include <iostream>

using namespace std;

int main()
{
    cout << "본인 피트를 입력하시오. __feet\b\b\b\b\b\b";
    int feet;
    cin >> feet;
    cout << "본인 인치를 입력하시오. __inch\b\b\b\b\b\b";
    int inch;
    cin >> inch;
    cout << "본인 파운드를 입력하시오. __pound\b\b\b\b\b\b\b\b";
    int pound;
    cin >> pound;
    
    const int feet_to_inch = 12;
    const double inch_to_meter = 0.0254;
    const float pound_to_kg = 2.2;
    
    inch = feet * feet_to_inch + inch;
    float kg = pound/pound_to_kg;
    double meter = (inch * inch_to_meter)*(inch * inch_to_meter);
    cout << "당신의 BMI는 " << kg/meter << "입니다.";
    return 0;
}
