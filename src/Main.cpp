#include <iostream>
#include "../header/TransactionManager.hpp"
#include "../header/Property.hpp"
#include "InventoryManager.cpp"
// #include "PropertyTree.hpp"
// #include "TerminalMenuController.hpp"
int main(){
    std::cout<<"Testing Linkedlist."<<std::endl;
    // TransactionManager manager;
    InventoryManager manager;  
    manager.run();


    // std::cout << "\n--- Launching Real Estate POS Menu ---" << std::endl;
    // TerminalMenuController menu;
    // menu.showMainMenu();

    return 0;
}