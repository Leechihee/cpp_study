#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <vector>
using namespace std;

template<typename T>
void scan_words(vector<T> & v);

void newlinedelete();

int main()
{
    srand(time(0));
    char play;
    cout << "영어 단어 게임을 하시겠습니까? (y/n) : ";
    cin >> play;
    newlinedelete();
    play = tolower(play);
    while(play != 'n')
    {
        vector<string> words;
        scan_words(words);
        const int NUM = words.size();
        cout << "스캔한 영단어 수는 " << NUM << "개 입니다.\n";
        
        string solution = words[rand() % NUM];
        int str_length = solution.length();
        string attempt(str_length,'-');
        string badchars;
        int guesses = 6;
        cout << "수수께끼 단어를 추측해 보십시오.\n"
            << str_length << "개의 문자로 이루어져 있습니다.\n"
            << "한번에 한 문자씩 추측하십시오\n"
            << "틀릴 수 있는 기회 : " << guesses << "번\n";
        cout << "추측하는 단어 : " << attempt << endl << endl;
        while(guesses > 0 && attempt != solution)
        {
            char ans;
            cout << "문자를 추측하시오 : ";
            cin >> ans;
            if(badchars.find(ans) != string::npos || attempt.find(ans) != string::npos)
            {
                cout << "이미 추측한 문자입니다. 다시 입력하시오 : ";
                continue;
            }
            int loc = solution.find(ans);
            if(loc == string::npos)
            {
                cout << "오답입니다.\n\n";
                --guesses;
                badchars += ans;
            }
            else
            {
                cout << "정답입니다.\n\n";
                attempt[loc] = ans;
                loc = solution.find(ans,loc+1);
                while(loc != string::npos)
                {
                    attempt[loc] = ans;
                    loc = solution.find(ans,loc+1);
                }
            }
            cout << "추측하는 단어 : " << attempt << endl;
            if(attempt != solution)
            {
                if(badchars.length() > 0)
                    cout << "오답 : " << badchars << endl;
                cout << "틀릴 수 있는 기회 : " << guesses << "번\n";
            }
        }
        if(guesses > 0)
            cout << "다 맞추었습니다.\n";
        else
            cout << "맞추지 못하였습니다. 정답은 " << solution << "이였습니다.\n";
        cout << "다시 하시겠습니까? (y/n) : ";
        cin >> play;
        play = tolower(play);
    }
    cout << "종료!";
    return 0;
}

template<typename T>
void scan_words(vector<T> & v)
{
    string temp;
    ifstream scan;
    scan.open("word.txt");
    while(scan >> temp)
        v.push_back(temp);
    scan.close();
}

void newlinedelete()
{
    while(cin.get() != '\n')
        continue;
}
