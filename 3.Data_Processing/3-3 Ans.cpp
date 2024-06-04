#include <iostream>

using namespace std;

int main()
{
    cout << "위도를 도, 분, 초 단위로 입력하시오: " << endl;
    int wedo, webun, wecho;
    cout << "먼저, 도각을 입력하시오: ";
    cin >> wedo;
    cout << "\n다음에, 분각을 입력하시오: ";
    cin >> webun;
    cout << "\n끝으로, 초각을 입력하시오: ";
    cin >> wecho;
    float output;
    output = float (wedo) + float (webun)/60 + float (wecho)/3600;
    cout << wedo << "도, " << webun << "분, " << wecho << "초 = "
    << output << "도";
    return 0;
}
