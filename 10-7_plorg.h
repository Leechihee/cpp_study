#ifndef PLORG_H_
#define PLORG_H_
#include <iostream>

class Plorg{
    char name[19];
    int ci = 50;
public:
    Plorg(char * Iname = "Plorga");
    void setCI(int n);
    void showPlorg() const;
};

#endif
