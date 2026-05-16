#include <iostream>
#include <string>
#include "../header/TransactionManager.hpp"
#include "../header/Property.hpp"
#include "../header/TerminalMenuController.hpp"
#include "InventoryManager.cpp"
#include "TerminalMenuController.cpp"

int main() {
    std::string username, password;

    std::cout << "=== Smart Real Estate POS Login ===" << std::endl;
    std::cout << "Username: ";
    std::cin >> username;
    std::cout << "Password: ";
    std::cin >> password;

    if (username == "admin" && password == "admin123") {
        std::cout << "\n✅ Login Successful! Accessing Admin Dashboard...\n" << std::endl;
        InventoryManager manager;  
        manager.run();
    } 
    else if (username == "user" && password == "user123") {
        std::cout << "\n✅ Login Successful! Accessing User Dashboard...\n" << std::endl;
        TerminalMenuController menu;
        menu.showMainMenu();
    } 
    // if invalid credentials are entered, the user will be notified and the program will terminate.
    else {
        std::cout << "\n❌ Invalid credentials! Access Denied." << std::endl;
    }

    return 0;
}


