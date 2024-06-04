#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> Lotto(int ,int);

int main()
{
    cout << "번호 공의 개수를 입력하시오 : ";
    int size;
    cin >> size;
    cout << "뽑을 공의 개수를 입력하시오 : ";
    int num;
    cin >> num;
    vector<int> victory(Lotto(size,num));
    cout << "이번주 로또 당첨번호는 " << endl;
    for(auto i = victory.begin(); i != victory.end(); i++)
        cout << *i << " ";
    cout << "\n입니다!" << endl;
    return 0;
}

vector<int> Lotto(int Size,int n)
{
    vector<int> temp(Size);
    for(int i = 0;i<Size;i++)
        temp[i] = i+1;
    random_shuffle(temp.begin(),temp.end());
    temp.erase(temp.begin() + n,temp.end());
    return temp;
}
