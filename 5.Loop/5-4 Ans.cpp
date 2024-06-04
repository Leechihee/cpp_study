#include <iostream>

using namespace std;

const float a_eja = 0.1, b_eja=1.05;

int main()
{
    int client_a = 100000, client_b = 100000;
    int client_a_eja = 100000;
    int count_years = 0;
    do
    {
        client_a += client_a_eja * a_eja;
        
        client_b = client_b * b_eja;
        
        count_years++;
    }while(client_a > client_b);
    cout << "A고객님은 원금 100,000원을 단리 10%인 금융상품에 가입하였고\n"
    << "B고객님은 원금 100,000원을 복리 5%인 금융상품에 가입하였다.\n"
    << "B고객이 A고객의 투자가치를 넘어서는 년수는 " << count_years << "년이고\n"
    << "그때 A고객과 B고객의 투자가치는 각각 " << client_a << " " << client_b
    << "이다.";
    return 0;
}
