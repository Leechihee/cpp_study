#include <iostream>

using namespace std;

void display(box);
void input(box);
//void output(box);

struct box
{
    char maker[40];
    float height; // 높이
    float width; // 세로
    float length; // 가로
    float volume; // 부피
};

int main()
{
    box big_box = {"Big box", 10, 20, 20, 4000};
    
    display(big_box);
    input(big_box);
    output(big_box);
    return 0;
}

void display(box n)
{
    cout << "박스의 이름은 " << n.maker << "이며\n"
    << "박스의 높이는 " << n.height << "이고\n"
    << "박스의 가로는 " << n.length << "이고 \n"
    << "박스의 세로는 " << n.width << "이다\n";
    << "이 박스의 부피는 " << n.volume << "이다\n";
}

void input(box n)
{
    cout << "새로운 박스의 정보를 입력하시오.\n";
    cout << "박스 회사의 이름을 입력하시오. : ";
    while(!(cin.getline(n.name))
        {
            cin.clear();
            while(cin.get() != '\n')
                continue;
            cout << "문자를 입력하시오.\n";
        }
}



