#include "TerminalMenuController.hpp"
#include <iostream>
#include <limits>
#include <iomanip>

TerminalMenuController::TerminalMenuController() {
    inventory.loadSampleProperties();
}

void TerminalMenuController::buyProperty() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "         AVAILABLE PROPERTIES           " << std::endl;
    std::cout << "========================================" << std::endl;
    inventory.displayAllProperties();

    if (inventory.getCount() == 0) {
        std::cout << "❌ No properties available for purchase." << std::endl;
        return;
    }

    int id;
    std::cout << "Enter Property ID to buy (0 to cancel): ";
    std::cin >> id;

    if (id == 0) {
        std::cout << "Purchase cancelled." << std::endl;
        return;
    }

    Property* prop = inventory.searchProperty(id);
    if (prop == nullptr) {
        std::cout << "❌ Property ID " << id << " not found." << std::endl;
        return;
    }

    std::cout << "\n--- Selected Property ---" << std::endl;
    prop->displayInfo();
    std::cout << "Confirm purchase? (y/n): ";
    char confirm;
    std::cin >> confirm;

    if (confirm == 'y' || confirm == 'Y') {
        Property bought = *prop;  // copy before it's removed
        transactionManager.processSale(bought);
        undoStack.push(bought);
        inventory.markAsSold(id);
        std::cout << "\n✅ Purchase successful! Transaction recorded." << std::endl;
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "💰 Total Revenue So Far: $" << transactionManager.getTotalRevenue() << std::endl;
    } else {
        std::cout << "Purchase cancelled." << std::endl;
    }
}

void TerminalMenuController::viewHistory() {
    std::cout << "\n========================================" << std::endl;
    std::cout << "          TRANSACTION HISTORY           " << std::endl;
    std::cout << "========================================" << std::endl;
    transactionManager.displayTransactions();
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "\n💰 Total Revenue: $" << transactionManager.getTotalRevenue() << std::endl;
    std::cout << "========================================" << std::endl;
}

void TerminalMenuController::undoLastTransaction() {
    if (undoStack.isEmpty()) {
        std::cout << "❌ No transactions to undo." << std::endl;
        return;
    }

    // Copy off stack before popping (peak() returns const ref)
    Property last = undoStack.peak();

    std::cout << "\n--- Last Transaction ---" << std::endl;
    last.displayInfo();
    std::cout << "Undo this transaction? (y/n): ";
    char confirm;
    std::cin >> confirm;

    if (confirm == 'y' || confirm == 'Y') {
        undoStack.pop();
        transactionManager.voidTransaction(last.getId());

        // Return property back to inventory
        Property* restored = new Property(
            last.getId(),
            last.getPropertyType(),
            last.getSector(),
            last.getPrice()
        );
        inventory.addProperty(restored);

        std::cout << "✅ Transaction undone. Property returned to inventory." << std::endl;
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "💰 Updated Total Revenue: $" << transactionManager.getTotalRevenue() << std::endl;
    } else {
        std::cout << "Undo cancelled." << std::endl;
    }
}

void TerminalMenuController::showMainMenu() {
    int choice = 0;

    while (choice != 4) {
        std::cout << "\n========================================" << std::endl;
        std::cout << "       SMART REAL ESTATE POS            " << std::endl;
        std::cout << "========================================" << std::endl;
        std::cout << "  1. 🏠 Buy Property" << std::endl;
        std::cout << "  2. 📋 View Transaction History" << std::endl;
        std::cout << "  3. ↩️  Undo Last Transaction" << std::endl;
        std::cout << "  4. 🚪 Exit" << std::endl;
        std::cout << "========================================" << std::endl;
        std::cout << "Enter your choice: ";

        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "❌ Invalid input. Please enter a number 1-4." << std::endl;
            continue;
        }

        switch (choice) {
            case 1:
                buyProperty();
                break;
            case 2:
                viewHistory();
                break;
            case 3:
                undoLastTransaction();
                break;
            case 4:
                std::cout << "\nThank you for using Smart Real Estate POS. Goodbye! 👋" << std::endl;
                break;
            default:
                std::cout << "❌ Invalid choice. Please enter 1-4." << std::endl;
                break;
        }
    }
}