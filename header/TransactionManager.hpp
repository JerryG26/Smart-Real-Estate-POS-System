#ifndef _TRANSACTION_MANAGER_H_
#define _TRANSACTION_MANAGER_H_
#include "Linkedlist.hpp"
#include "Property.hpp"


class TransactionManager{
    private:
    Linkedlist salesHistory;
    double totalRevenue;

    public:
    TransactionManager();
    void processSale(const Property& p);
    bool voidTransaction(int id);
    void displayTransactions()const;
    double getTotalRevenue()const;
    Property *searchTransactions(int id);
};
#endif