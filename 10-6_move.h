#include <iostream>

class Move{
    double x;
    double y;
public:
    Move(double a = 0, double b = 0);
    Move add(const Move & m) const;
    void showMove() const;
    void reset(double a = 0, double b = 0);
};
