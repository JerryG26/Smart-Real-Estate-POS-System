#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_
#include "Node.hpp"
#include "Property.hpp"
class Linkedlist{
    private:
    Node *head;
    Node *tail;

    public:
    Linkedlist();
    ~Linkedlist();
    bool addTransactions(const Property &data);
    bool removeTransaction(int id);
    bool removeFront();
    const Property *frontOfQueue()const;
    bool isEmpty()const;
    void display()const;
    Property *searchID(int id);
};
#endif