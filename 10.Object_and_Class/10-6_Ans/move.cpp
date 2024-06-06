#include <iostream>
#include "move.h"

namespace
{
    using std::cout;
    using std::endl;
}

Move::Move(double a,double b)
{
    x = a;
    y = b;
}

Move Move::add(const Move & m) const
{
    double newX = this->x;
    double newY = this->y;
    newX += m.x;
    newY += m.y;
    Move newMove(newX,newY);
    return newMove;
}

void Move::showMove() const
{
    cout << x << " " << y << endl;
}

void Move::reset(double a, double b)
{
    x = a;
    y = b;
}
