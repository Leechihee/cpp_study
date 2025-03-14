#include <iostream>

using namespace std;

struct box
{
    char maker[40];
    float height; // 높이
    float width; // 세로
    float length; // 가로
    float volume; // 부피
};

void display(box n);
void input(box *n);
float output(box);

int main()
{
    box bigbox = {"Big box", 10.0, 20.0, 20.0, 4000.0};
    
    display(bigbox);
    input(&bigbox);
    cout << "새로운 박스의 이름은 " << bigbox.maker << "이며 \n"
    << "새로운 박스의 부피는 " << output(bigbox) << "이다.";
    return 0;
}

void display(box n)
{
    cout << "박스의 이름은 " << n.maker << "이며\n"
    << "박스의 높이는 " << n.height << "이고\n"
    << "박스의 가로는 " << n.length << "이고 \n"
    << "박스의 세로는 " << n.width << "이다\n"
    << "이 박스의 부피는 " << n.volume << "이다\n";
}

void input(box *n)
{
    cout << "새로운 박스의 정보를 입력하시오.\n";
    cout << "박스 회사의 이름을 입력하시오. : ";
    cin.getline(n->maker, 40); 
    cout << "박스의 높이를 입력하시오. : ";
    while(!(cin>>n->height))
    {
        cin.clear();
        if(cin.get() != '\n')
            continue;
        cout << "숫자를 입력하시오. : ";
    }
    cout << "박스의 가로길이를 입력하시오. : ";
    while(!(cin>>n->length))
    {
        cin.clear();
        if(cin.get() != '\n')
            continue;
        cout << "숫자를 입력하시오. : ";
    }
    cout << "박스의 세로길이를 입력하시오. : ";
    while(!(cin>>n->width))
    {
        cin.clear();
        if(cin.get() != '\n')
            continue;
        cout << "숫자를 입력하시오. : ";
    }
}

float output(box n)
{
    return n.height*n.width*n.length;
}
