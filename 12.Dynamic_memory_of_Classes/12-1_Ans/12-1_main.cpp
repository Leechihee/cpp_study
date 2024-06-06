#include "cow.h"
#include <iostream>
using std::cout;

int main()
{
    Cow arrC[3] = {Cow("lee","kim",10),Cow(arrC[0])};
    arrC[2] = arrC[0];
    for(int i = 0;i<3;i++)
    {
        cout << i+1 << " : ";
        arrC[i].ShowCow();
    }
    return 0;
}
