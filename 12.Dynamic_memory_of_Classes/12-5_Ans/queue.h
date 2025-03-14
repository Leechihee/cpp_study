#ifndef QUEUE_H_
#define QUEUE_H_
#include <iostream>

class Customer{
    long arrive;
    int processtime;
public:
    Customer() {arrive = processtime = 0;}
    void set(long when);
    long when() const {return arrive;}
    int ptime() const {return processtime;}
};

typedef Customer Item;

class Queue{
    struct Node { Item item; struct Node * next;};
    enum { Q_SIZE = 10};
    Node * front = NULL;
    Node * rear = NULL;
    int items = 0;
    const int qsize;
    Queue(const Queue & q) : qsize(0) {}
    Queue & operator=(const Queue & q) {return *this;}
public:
    Queue(int qs = Q_SIZE);
    ~Queue();
    bool isempty() const;
    bool isfull() const;
    int queuecount() const;
    bool enqueue(const Item & item);
    bool dequeue(Item & item);
};

#include "queue.cpp"
#endif
