#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    cout << "단어들을 입력하시오. (끝내려면 q) :\n";
    string word;
    int ct = 0, ct2 = 0, ct3 = 0;
    cin >> word;
    while(word != "q")
    {
        if(isalpha(word[0]) == 0)
            ct3++;
        else
        {
            if(!(isupper(word[0])))
                word[0] = toupper(word[0]);
            if(word[0] == 'A' || word[0] == 'E' || word[0] == 'I' || word[0] == 'O' || word[0] == 'U')
                ct2++;
            else
                ct++;
        }
        cin >> word;
    }
    cout << "모음으로 시작하는 단어는 " << ct2 << "개이다.\n";
    cout << "자음으로 시작하는 단어는 " << ct << "개이다.\n";
    cout << "기타 : " << ct3;
    return 0;
}
