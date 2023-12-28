#include <iostream>


typedef struct Linked_List
{
    double N;
    struct Linked_List * next = NULL;
}node;

class List{
    node * head = new node;
public:
    List();
    void setIndexVelue(double n);
    void showIndex();
    void useIndexVelue(void (*pf)(double &));
};
