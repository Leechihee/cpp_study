#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char word[100];
    int count = 0;
    cout << "영어 단어들을 입력하십시오 (끝낼려면 done을 입력) : " << endl;
    cin >> word;
    
    while(word && strcmp("done",word))
    {
        ++count;
        cin >> word;
    }
    cout << "총 " << count << " 단어가 입력되었습니다.";
    return 0;
}
