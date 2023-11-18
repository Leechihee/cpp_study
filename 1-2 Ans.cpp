#include <iostream>
double mail(int);

using namespace std;

int main(){
    int input;
    cout << "여기에 마일을 정수로 입력하시오." << endl;
    cin >> input;
    
    cout << input << "마일은 "
    << mail(input) << "킬로미터입니다."
    << endl;
    return 0;
}

double mail(int n)
{
    return n * 1.60934;
}
