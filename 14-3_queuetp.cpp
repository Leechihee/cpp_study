#include "queuetp.h"
#include "worker.h"

//Queuetp public method
template<class T>
QueueTP<T>::~QueueTP()
{
    node * temp;
    while(head->next != NULL)
    {
        temp = head->next;
        head->next = temp->next;
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
bool QueueTP<T>::enqueue(const T item)
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
bool QueueTP<T>::dequeue(int i,T item)
{
    if(isempty())
        return false;
    node * temp;
    node * before = head;
    for(int j = 0;j<i;j++)
        before = before->next;
    temp = before;
    before = before->next;
    item = temp->ITEM;
    delete temp;
    items--;
    return true;
}

template<class T>
T & QueueTP<T>::operator[](int i)
{
    node * temp = head;
    for(int j = 0;j<i;j++)
        temp = temp->next;
    return temp->ITEM;
}

template class QueueTP<Worker*>;
