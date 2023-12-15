#include <iostream>

using namespace std;

const int size = 80;

struct Candybar
    {
        char *made;
        double waight;
        int kalory;
    };
    
    
void fill(Candybar &, char *,double,int);
void show(const Candybar &);

int main()
{
    Candybar candy;
    fill(candy,(char*)"Millennium Munch",2.85,350);
    show(candy);
    return 0;
}

void fill(Candybar &can, char *str,double a,int b)
{
    can.made = str;
    can.waight = a;
    can.kalory = b;
}

void show(const Candybar &can)
{
    cout << "상표 : " << can.made << "\n" << "중량 : " <<can.waight << "\n열량 : " << can.kalory << endl;
}
