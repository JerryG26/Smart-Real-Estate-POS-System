#include <iostream>
#include "Queue.hpp"

Queue::Queue(){
    
}

bool Queue::enqueue(const Property &p){
    flowList.addTransactions(p);
    std::cout<<"Transaction added to queue.";
}
bool Queue::dequeue(){
    flowList.removeFront();
}
bool Queue::isEmpty()const{
    return flowList.isEmpty();
}
const Property& Queue::front() const{
    flowList.frontOfQueue();
}