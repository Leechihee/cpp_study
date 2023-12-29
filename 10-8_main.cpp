#include <iostream>
#include "List.h"

void sq(double &);

int main()
{
    List Mylist;
    Mylist.setIndexVelue(10);
    Mylist.setIndexVelue(11);
    Mylist.setIndexVelue(12);
    Mylist.showIndex();
    Mylist.useIndexVelue(sq);
    Mylist.showIndex();
    return 0;
}

void sq(double & n)
{
    n = n*n;
}
