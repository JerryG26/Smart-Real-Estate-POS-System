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
    void addTransactions(Property data);
    Property *removeTransaction(int id);
    void displayTransactions();
    double calculateSales();
    Property *searchTransactions(int id);
};
#endif