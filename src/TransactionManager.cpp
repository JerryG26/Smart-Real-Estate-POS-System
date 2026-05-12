#include "TransactionManager.hpp"
#include <iostream>

TransactionManager::TransactionManager():totalRevenue{0.0}{}

void TransactionManager::processSale(const Property& p){
    if (salesHistory.addTransactions(p)) { 
        totalRevenue += p.getPrice();      
    }
}
void TransactionManager::displayTransactions()const{
    salesHistory.display();
}
double TransactionManager::getTotalRevenue()const{
    return totalRevenue;
}
Property *TransactionManager::searchTransactions(int id){
    return salesHistory.searchID(id);
}

bool TransactionManager::voidTransaction(int id){
    Property* p = salesHistory.searchID(id);
    if (p != nullptr){
        totalRevenue -= p->getPrice();
        if (salesHistory.removeTransaction(id)){
            std::cout << "Transaction " << id << " has been voided." << std::endl;
            return true;
        }
    }
    std::cout << "Transaction ID not found." << std::endl;
    return false;
}