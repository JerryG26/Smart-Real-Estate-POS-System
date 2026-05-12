#include "PropertyArray.hpp"
#include <iostream>
#include <sstream>

using namespace std;

PropertyArray::PropertyArray() {
    propertyCount = 0;
    for(int i = 0; i < MAX_PROPERTIES; i++) {
        properties[i] = nullptr;
    }
}

PropertyArray::~PropertyArray() {
    for(int i = 0; i < propertyCount; i++) {
        delete properties[i];
        properties[i] = nullptr;
    }
}

bool PropertyArray::addProperty(Property* prop) {
    if(propertyCount < MAX_PROPERTIES) {
        properties[propertyCount] = prop;
        propertyCount++;
        cout << "✅ Property added! Total: " << propertyCount << "/" << MAX_PROPERTIES << endl;
        return true;
    }
    cout << "❌ Inventory full! Cannot add more properties." << endl;
    return false;
}

Property* PropertyArray::getProperty(int index) {
    if(index >= 0 && index < propertyCount) {
        return properties[index];
    }
    return nullptr;
}

int PropertyArray::findPropertyIndex(int id) {
    for(int i = 0; i < propertyCount; i++) {
        if(properties[i]->getId() == id) {
            return i;
        }
    }
    return -1;
}

Property* PropertyArray::searchProperty(int id) {
    int index = findPropertyIndex(id);
    if(index != -1) {
        return properties[index];
    }
    return nullptr;
}

bool PropertyArray::removeProperty(int id) {
    int index = findPropertyIndex(id);
    if(index != -1) {
        delete properties[index];

        for(int i = index; i < propertyCount - 1; i++) {
            properties[i] = properties[i + 1];
        }
        properties[propertyCount - 1] = nullptr;
        propertyCount--;
        cout << "✅ Property " << id << " removed!" << endl;
        return true;
    }
    cout << "❌ Property " << id << " not found!" << endl;
    return false;
}

void PropertyArray::loadSampleProperties() {
    cout << "\n🏠 Loading properties into inventory (Filling the shelf)..." << endl;
    
    Property* p1 = new Property(1001, "House", "Residential", 350000.00);
    Property* p2 = new Property(1002, "Condo", "Residential", 275000.00);
    Property* p3 = new Property(1003, "Lot", "Commercial", 85000.00);
    Property* p4 = new Property(1004, "Townhouse", "Residential", 310000.00);
    Property* p5 = new Property(1005, "Warehouse", "Industrial", 520000.00);
    Property* p6 = new Property(1006, "Apartment", "Residential", 425000.00);
    Property* p7 = new Property(1007, "Office Space", "Commercial", 480000.00);
    
    addProperty(p1);
    addProperty(p2);
    addProperty(p3);
    addProperty(p4);
    addProperty(p5);
    addProperty(p6);
    addProperty(p7);
    
    cout << "✅ Loaded " << propertyCount << " properties into inventory!" << endl;
}

bool PropertyArray::markAsSold(int id) {
    int index = findPropertyIndex(id);
    if(index != -1) {
        Property* prop = properties[index];
        
        cout << "\n========================================" << endl;
        cout << "        DEAL COMPLETED!                 " << endl;
        cout << "========================================" << endl;
        cout << "Property being sold:" << endl;
        prop->displayInfo();
        
        removeProperty(id);
        
        cout << "\n✅ Property " << id << " has been SOLD!" << endl;
        cout << "   (Deal completed - property removed from available inventory)" << endl;
        cout << "========================================\n" << endl;
        return true;
    }
    cout << "❌ Property with ID " << id << " not found. Cannot mark as sold." << endl;
    return false;
}

void PropertyArray::displayAllProperties() {
    if(propertyCount == 0) {
        cout << "\n📭 No properties available in inventory." << endl;
        return;
    }

    for(int i = 0; i < propertyCount; i++) {
        cout << "[" << i+1 << "] ";
        properties[i]->displayInfo();
        cout << "----------------------------------------" << endl;
    }
}

int PropertyArray::getCount() const {
    return propertyCount;
}

string PropertyArray::getPropertiesAsJSON() {
    stringstream ss;
    ss << "[\n";
    for(int i = 0; i < propertyCount; i++) {
        ss << "  {\n";
        ss << "    \"id\": " << properties[i]->getId() << ",\n";
        ss << "    \"type\": \"" << properties[i]->getPropertyType() << "\",\n";
        ss << "    \"sector\": \"" << properties[i]->getSector() << "\",\n";
        ss << "    \"price\": " << properties[i]->getPrice() << "\n";
        ss << "  }";
        if(i < propertyCount - 1) {
            ss << ",";
        }
        ss << "\n";
    }
    ss << "]";
    return ss.str();
}