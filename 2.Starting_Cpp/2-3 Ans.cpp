#include <iostream>
void three(void);
void see(void);

using namespace std;

int main()
{
    three();
    three();
    see();
    see();
    
    return 0;
}


void three(void)
{
    cout << "Three blind mice" << endl;
}

void see(void)
{
    cout << "See how they run" << endl;
}
