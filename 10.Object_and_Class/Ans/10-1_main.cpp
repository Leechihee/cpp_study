#include <iostream>
#include "../header/bank.h"

int main()
{
    bank b1;
    bank b2("lee chi hee","fgkwac", 1000);
    b1.show();
    b2.show();
    b2.inMoney(2000);
    b2.show();
    b2.outMoney(5000);
    b2.outMoney(1000);
    b2.show();
    return 0;
}
