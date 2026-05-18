#pragma once
#include "PropertyArray.hpp"
#include "TransactionManager.hpp"
#include "Stack.hpp"

class TerminalMenuController {
private:
    PropertyArray inventory;
    TransactionManager transactionManager;
    Stack undoStack;

    void buyProperty();
    void viewHistory();
    void undoLastTransaction();

public:
    TerminalMenuController();
    void showMainMenu();
};