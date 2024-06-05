#ifndef LIST_H_
#define LIST_H_

#include <iostream>

class List{
    typedef struct Linked_List
    {
        double N;
        struct Linked_List * next = NULL;
    }node;
    node * head = new node;
public:
    List();
    ~List();
    void setIndexVelue(double n);
    void showIndex();
    void useIndexVelue(void (*pf)(double &));
};

#include "List.cpp"
#endif
