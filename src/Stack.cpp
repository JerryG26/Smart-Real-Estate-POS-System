#include "Stack.hpp"
#include <cstdlib>
#include <iostream>
Stack::Stack(): top{-1},capacity{5}{
    array = new Property[capacity];
}

Stack::~Stack(){
    delete[] array;
}

bool Stack::push(const Property &p){
    if(capacity == 5){
        resize();
    }
    array[++top] = p;
    return true;
}

bool Stack::pop(){
    if(isEmpty()){
        std::cout<<"Stack is empty.";
        return false;
    }
    top--;
    return true;
}

bool Stack::isEmpty() const{
    return top == -1;
}

const Property &Stack::peak()const{
    return array[top];
}

void Stack::resize(){
    int newCapacity = capacity*2;
    Property *newArray = new Property[newCapacity];

    for(int i{0}; i < capacity; i++){
        newArray[i] = array[i];
    }
    delete[] array;
    array = newArray;
    capacity = newCapacity;
}