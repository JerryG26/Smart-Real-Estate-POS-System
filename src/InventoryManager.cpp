#include "PropertyArray.hpp"
#include <iostream>
#include <string>

using namespace std;

class InventoryManager {
    private:
        PropertyArray propertyArray;  
    
    public:
        void run(){
            int choice;
            do{
                cout << "\n=== INVENTORY MANAGEMENT SYSTEM ===" << endl;
                cout << "1. Load Sample Properties (Fill the shelf)" << endl;
                cout << "2. Display All Properties" << endl;
                cout << "3. Search Property by ID" << endl;
                cout << "4. Mark Property as Sold" << endl;
                cout << "5. Exit" << endl;
                cout << "Enter your choice: ";
                cin >> choice;

                switch(choice) {
                    case 1:
                        propertyArray.loadSampleProperties();
                        break;
                        
                    case 2:
                        propertyArray.displayAllProperties();
                        break;
                        
                    case 3: {
                        int id;
                        cout << "Enter Property ID: ";
                        cin >> id;

                        Property* p = propertyArray.searchProperty(id);
                        if (p) {
                            cout << "\n✅ Property found:" << endl;
                            p->displayInfo();
                        } else {
                            cout << "❌ Property not found!" << endl;
                        }
                        break;
                    }
                    
                    case 4: {
                        int id;
                        cout << "Enter Property ID to sell: ";
                        cin >> id;

                        propertyArray.markAsSold(id);
                        break;
                    }
                    
                    case 5:
                        cout << "Goodbye!" << endl;
                        break;
                        
                    default:
                        cout << "Invalid choice!" << endl;
                }
            } while(choice != 5);
        }
}; 

