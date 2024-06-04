#include <iostream>

using namespace std;

int main()
{
    cout << "다음 선택 사항 중에서 하나를 선택하시오. (끝내려면 q)\n";
    cout << "c) camera      p)pianist\nt) tree        g) game\n";
    char ch;
    cin >> ch;
    while(ch != 'q')
        {
            switch (ch)
            {
                case 'c':
                {
                    cout << "찰칵!\n";
                    cin >> ch;
                    continue;
                }
                case 'p':
                {
                    cout << "피아노를 치는 사람\n";
                    cin >> ch;
                    continue;
                }
                case 't':
                {
                    cout << "단풍나무는 잎이 별처럼 생겼습니다.\n";
                    cin >> ch;
                    continue;
                }
                case 'g':
                {
                    cout << "게임을 시작합니다.\n";
                    cin >> ch;
                    continue;
                }
                default:
                {
                    cout << "c, p, t, g 중에서 하나를 선택하십시오. (끝내려면 q) : ";
                    cin >> ch;
                }
            }
        }
    cout << "프로그램을 종료하겠습니다.";
    return 0;
}
