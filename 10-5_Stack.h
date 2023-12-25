#include <iostream>

typedef unsigned long Item;

class Stack{
    enum {MAX=10};
    Item[MAX];
    int top;
public:
    Stack();
    bool isempty() const;
    bool isfull() const;
    bool push(const Item & Item);
    bool pop(Item & Item);
};
