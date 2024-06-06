#include <iostream>
#include "Stack.h"

Stack::Stack()
{
    top = 0;
}

bool Stack::isempty() const
{
    return top == 0;
}

bool Stack::isfull() const
{
    return top == MAX;
}

bool Stack::push(const Item & item)
{
    if(top < MAX)
    {
        for(int i = 0;item.fullname[i] != '\0';i++)
            items[top].fullname[i] = item.fullname[i];
        items[top].payment = item.payment;
        top++;
        return true;
    }
    else
        return false;
}

bool Stack::pop(Item & item)
{
    if(top > 0)
    {
        --top;
        for(int i = 0;item.fullname[i] != '\0';i++)
            item.fullname[i] = items[top].fullname[i];
        item.payment = items[top].payment;
        return true;
    }
    else
        return false;
}
