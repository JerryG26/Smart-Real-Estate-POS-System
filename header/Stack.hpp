#ifndef _STACK_H_
#define _STACK_H_
#include "Property.hpp"

class Stack{
    private:
    int top;
    int capacity;
    Property *array;
    void resize();

    public:
    Stack();
    ~Stack();
    bool push(const Property &p);
    bool pop();
    bool isEmpty() const;
    const Property &peak()const;

};
#endif