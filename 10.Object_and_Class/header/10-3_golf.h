#ifndef GOLF_H_
#define GOLF_H_
#include <iostream>

class golf{
    static const int Len = 40;
    struct Golf
    {
        char fullname[Len];
        int handicap;
    }GOLF;
public:
    golf() {GOLF.fullname[0] = '\0'; GOLF.handicap = 0;}
    golf(const char *name, int hc);
    golf setgolf();
    void handicap(int hc);
    void showgolf() const;
};

#endif
