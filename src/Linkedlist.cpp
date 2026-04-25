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
bool Linkedlist::addTransactions(Property data){
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
void Linkedlist::displayTransactions(){
    Node *curr{head};
    while(curr){
        curr->data.displayInfo();
        curr = curr->next;
    }
    
}
double Linkedlist::calculateSales(){
    double total{0};
    Node *curr{head};
    while(curr){
        total = total+curr->data.getPrice();
        curr = curr->next;
    }
    return total;
}
Property *Linkedlist::searchTransactions(int id){
    Node *temp{head};
    while(temp){
        if(id == temp->data.getId()){
            return &temp->data;
        }
        temp = temp->next;
    }

    return nullptr;
}