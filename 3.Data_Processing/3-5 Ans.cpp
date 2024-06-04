#include <iostream>

using namespace std;

int main()
{
    cout << "세계 인구수를 입력하시오:";
    long long world_ingu,local_ingu;
    cin >> world_ingu;
    cout << "미국의 인구수를 입력하시오:";
    cin >> local_ingu;
    cout << "세계 인구수에서 미국이 차지하는 비중은 "
    << float (local_ingu) / float (world_ingu) *100
    << "%이다.";
    return 0;
}
