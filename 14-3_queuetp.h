#ifndef QUEUETP_H_
#define QUEUETP_H_

#include <iostream>

template<class T>
class QueueTP{
    struct node
    {
        T ITEM;
        struct node * next = NULL;
    };
    enum {QSIZE = 10};
    node * head = new node;
    int items = 0;
    const int qsize;
    QueueTP(const QueueTP & qt) : qsize(0) {}
    QueueTP & operator=(const QueueTP & qt) {return *this;}
public:
    QueueTP(int n = QSIZE) : qsize(n) {}
    ~QueueTP();
    bool isempty() const;
    bool isfull() const;
    int queuecount() const;
    bool enqueue(const T item);
    bool dequeue(int i, T item);
    T & operator[](int i);
};
#endif
