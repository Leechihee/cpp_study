#include <iostream>
#include "List.h"

namespace
{
    using std::cout;
    using std::endl;
}

List::List()
{
    head->next = NULL;
    cout << "리스트를 선언하였습니다.\n";
}

void List::setIndexVelue(double n)
{
    node * newIndex = new node;
    node * beforeIndex;
    newIndex->N = n;
    newIndex->next = NULL;
    if(head->next == NULL)
    {
        head->next = newIndex; // head->newIndex
        return;
    }
    beforeIndex = head->next;
    while(beforeIndex->next != NULL) 
        beforeIndex = beforeIndex->next;
    beforeIndex->next = newIndex;
}

void List::showIndex()
{
    node * Index = head->next;
    while(Index->next != NULL)
    {
        cout << Index->N << endl;
        Index = Index->next;
    }
    cout << Index->N << endl;
}

void List::useIndexVelue(void (*pf)(double &))
{
    node * beforeIndex = head->next;
    while(beforeIndex->next != NULL)
    {
        pf(beforeIndex->N);
        cout << endl;
        beforeIndex = beforeIndex->next;
    }
    pf(beforeIndex->N);
    cout << endl;
}
