#include <iostream>
#include "Linkedlist.hpp"
#include "Property.hpp"
#include "PropertyTree.hpp"
#include "TerminalMenuController.hpp"
int main(){
    std::cout<<"Testing Linkedlist."<<std::endl;
    Linkedlist list;
    list.addTransactions(Property(1,"type1","sector1",11.5));
    list.addTransactions(Property(2,"type2","sector2",12.5));
    list.addTransactions(Property(3,"type3","sector3",13.5));
    list.addTransactions(Property(4,"type4","sector4",14.5));
    list.addTransactions(Property(5,"type5","sector5",15.5));
    list.addTransactions(Property(6,"type6","sector6",16.5));
    list.removeTransaction(2);
    list.displayTransactions();

    std::cout << "\n--- Launching Real Estate POS Menu ---" << std::endl;
    TerminalMenuController menu;
    menu.showMainMenu();

    return 0;
}