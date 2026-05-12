#include <iostream>
#include "Queue.hpp"

Queue::Queue(){
    
}

bool Queue::enqueue(const Property &p){
    flowList.addTransactions(p);
    std::cout<<"Transaction added to queue."<<std::endl;
    return true;
}
bool Queue::dequeue(){
    return flowList.removeFront();
}
bool Queue::isEmpty()const{
    return flowList.isEmpty();
}
const Property& Queue::front() const{
    const Property* p = flowList.frontOfQueue();
    if(p == nullptr){
        throw std::runtime_error("Queue is empty: cannot access front.");
    }
    return *p;
}