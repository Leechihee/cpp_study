#include <iostream>
#include "../header/plorg.h"

int main()
{
    Plorg p[2] = {Plorg(),Plorg("Lee Chi Hee")};
    p[0].showPlorg();
    p[1].showPlorg();
    p[0].setCI(45);
    p[1].setCI(65);
    p[0].showPlorg();
    p[1].showPlorg();
    return 0;
}

