#ifndef _QUEUE_H_
#define _QUEUE_H_
#include "Linkedlist.hpp"
#include "Property.hpp"

class Queue{
    private:
    Linkedlist flowList;

    public:
    Queue();
    bool enqueue(const Property &p);
    bool dequeue();
    bool isEmpty()const;
    const Property& front() const;
};
#endif