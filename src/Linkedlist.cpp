#include "Linkedlist.hpp"
#include <iostream>
Linkedlist::Linkedlist():head{nullptr},tail{nullptr}{}
Linkedlist::~Linkedlist(){
    while(head){
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    head = tail = nullptr;
}
bool Linkedlist::addTransactions(const Property &data){
    Node *newData = new Node(data);

    if(!head){
        head = tail = newData;
    }else{
        newData->prev = tail;
        tail->next = newData;
        tail = newData;
    }
    return true;
}
bool Linkedlist::removeTransaction(int id){
    if(!head){
        std::cout<<"Transaction is empty."<<std::endl;
        return false;
    }

    Node *curr{head};
    Node *prev{nullptr};
    while(curr){
        if(curr->data.getId() == id){
            if(curr == head){
                Node *temp{head};
                head = head->next;
                delete temp;
            }else{
                if(curr == tail){
                    tail = prev;
                }
                prev->next = curr->next;
                delete curr;
            }
            return true;
        }
        prev = curr;
        curr = curr->next;
    }
    return false;
    
}

bool Linkedlist::removeFront(){
    if(isEmpty()){
        std::cout<<"The list is empty";
       return false; 
    } 

    Node *temp{head};
    head = head->next;
    delete temp;
    return true;

}
bool Linkedlist::isEmpty()const{
    return (!head && !tail);
}

const Property *Linkedlist::frontOfQueue()const{
    if(!head) return nullptr;
    return &head->data;
}

Property *Linkedlist::searchID(int id){
    Node *curr{head};
    while(curr){
        if(curr->data.getId() == id){
            return &curr->data;
        }
        curr = curr->next;
    }
    return nullptr;
}

void Linkedlist::display()const{
    if(isEmpty()){
        std::cout<<"The list is empty."<<std::endl;
        return;
    }
    Node *curr{head};
    while(curr){
        curr->data.displayInfo();
        curr = curr->next;
    }
}