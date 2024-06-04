#include <iostream>
#include <string>

using namespace std;

int main()
{
    string name;
    string dessert;
    
    cout << "이름을 입력하시오 : ";
    getline(cin,name);
    cout << "좋아하는 디저트를 입력하시오 : ";
    getline(cin,name);
    
    cout << "맛있는 " << dessert << "를 준비하겠습니다. "
    << name << "님!";
    
    return 0;
}
