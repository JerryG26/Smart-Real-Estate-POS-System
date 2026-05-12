#include <iostream>
#include "../header/TransactionManager.hpp"
#include "../header/Property.hpp"
// #include "PropertyTree.hpp"
// #include "TerminalMenuController.hpp"
int main(){
    std::cout<<"Testing Linkedlist."<<std::endl;
    TransactionManager manager;

    manager.processSale(Property(1,"House","Residential",125));
    manager.processSale(Property(2,"House","Residential",125));
    manager.processSale(Property(3,"House","Residential",125));
    manager.processSale(Property(4,"House","Residential",125));
    manager.displayTransactions();

    // std::cout << "\n--- Launching Real Estate POS Menu ---" << std::endl;
    // TerminalMenuController menu;
    // menu.showMainMenu();

    return 0;
}