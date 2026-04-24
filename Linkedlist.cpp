#include "Linkedlist.hpp"

Linkedlist::Linkedlist():head{nullptr},tail{nullptr}{}
Linkedlist::~Linkedlist(){
    while(head){
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    head = tail = nullptr;
}
void Linkedlist::addTransactions(Property data){
    Node *newData = new Node(data);

    if(!head){
        head = tail = newData;
    }else{
        tail->next = newData;
        tail = newData;
    }
}
Property *Linkedlist::removeTransaction(int id){

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
    bool check{false};
    Property *property{nullptr};
    while(temp){
        if(id == temp->data.getId()){
            check = true;
            property = &temp->data;
            break;
        }
        temp = temp->next;
    }

    if(check){
        return property;
    }else{
        return nullptr;
    }
}