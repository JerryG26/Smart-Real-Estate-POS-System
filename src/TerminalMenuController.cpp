#include "TerminalMenuController.hpp"
#include <iostream>

void TerminalMenuController::showMainMenu() {
    int choice = 0;
    
    while (choice != 4) {
        std::cout << "\n=== Main Menu ===" << std::endl;
        std::cout << "1. Buy Property" << std::endl;
        std::cout << "2. View History" << std::endl;
        std::cout << "3. Undo" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        
        std::cin >> choice;
        
        switch (choice) {
            case 1:
                std::cout << "You selected: Buy Property" << std::endl;
                // Logic for Buying property goes here
                break;
            case 2:
                std::cout << "You selected: View History" << std::endl;
                // Logic for Viewing History goes here
                break;
            case 3:
                std::cout << "You selected: Undo" << std::endl;
                // Logic for Undo goes here
                break;
            case 4:
                std::cout << "Exiting system..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    }
}
