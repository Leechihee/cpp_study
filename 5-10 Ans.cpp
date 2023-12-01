#include <iostream>
#include <string>

using namespace std;

int main()
{
    string word;
    int count = 0;
    cout << "영어 단어들을 입력하십시오 (끝낼려면 done을 입력) : " << endl;
    cin >> word;
    while(word != "done")
    {
        ++count;
        cin >> word;
    }
    cout << "총 " << count << " 단어가 입력되었습니다.";
    return 0;
}
