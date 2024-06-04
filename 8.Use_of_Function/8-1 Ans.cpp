#include <iostream>

using namespace std;

const int size = 80;
int count = 0;

void show(char *str, int n = 0);

int main()
{
    char str[size];
    int i;
    cout << "문자열을 입력하시오.\n";
    cin.getline(str,size);
    show(str);
    show(str,0);
    show(str,100);
    
    for(int i = 0;i<3;i++)
        show(str);
    show(str,0);
    show(str,3000);
    return 0;
}

void show(char *str, int n)
{
    if(n==0)
    {
        cout << str << endl;
        count++;
    }
    else
    {
        for(int i = 0;i<count;i++)
            cout << str << endl;
    }
}
