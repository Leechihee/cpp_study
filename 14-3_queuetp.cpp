#include "queuetp.h"

//Queuetp public method
template<class T>
QueueTP<T>::~QueueTP()
{
    node * temp;
    for(int i =0;head->next != NULL;i++)
    {
        head = head->next->next;
        temp = head->next;
        delete temp; 
    }
    delete head;
}

template<class T>
bool QueueTP<T>::isempty() const
{
    return items==0;
}

template<class T>
bool QueueTP<T>::isfull() const
{
    return items==qsize;
}

template<class T>
int QueueTP<T>::queuecount() const
{
    return items;
}

template<class T>
bool QueueTP<T>::enqueue(const T & item)
{
    if(isfull())
        return false;
    node * New = new node;
    New->ITEM = item;
    New->next = NULL;
    if(head->next == NULL)
    {
        head->next = New;
        items++;
        return true;
    }
    node * temp = head;
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = New;
    items++;
    return true;
}

template<class T>
bool QueueTP<T>::dequeue(T & item)
{
    if(isempty())
        return false;
    node * temp = head;
    while(temp->next != NULL)
        temp = temp->next;
    item = temp->ITEM;
    items--;
    delete temp;
    return true;
}
