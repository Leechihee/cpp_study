#include <iostream>
#include "move.h"

int main()
{
    Move move[2] = {Move(1,1), Move(10,5)};
    move[0].showMove();
    move[1].showMove();
    move[0] = move[0].add(move[1]);
    move[0].showMove();
    move[0].reset(100,50);
    move[0].showMove();
    return 0;
}
