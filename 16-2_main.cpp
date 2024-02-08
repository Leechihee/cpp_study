#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

bool palindrome(string & s);

int main()
{
    string ans;
    
    cout << "단어를 입력하시오 (끝내려면 quit) : ";
    while(getline(cin,ans) && ans != "quit")
    {
        if(palindrome(ans))
            cout << "회문입니다!\n";
        else
            cout << "회문이 아닙니다!\n";
        cout << "단어를 입력하시오 (끝내려면 quit) : ";
    }
    return 0;
}

bool palindrome(string & s)
{
    for(auto i = s.begin(); i != s.end();i++)
    {
        if(ispunct(*i) || isblank(*i))
            i = s.erase(i) - 1;
        *i = tolower(*i);
    }
    string temp = s;
    reverse(temp.begin(),temp.end());
    return s == temp;
}
