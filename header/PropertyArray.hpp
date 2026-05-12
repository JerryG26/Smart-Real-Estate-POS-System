#ifndef PROPERTYARRAY_HPP
#define PROPERTYARRAY_HPP

#include "Property.hpp"
#include <string>

#define MAX_PROPERTIES 100   

class PropertyArray {
private:
    Property* properties[MAX_PROPERTIES];  
    int propertyCount;                      
    
public:
    
    PropertyArray();
    
    ~PropertyArray();
    
    bool addProperty(Property* prop);
    Property* getProperty(int index);
    int findPropertyIndex(int id);
    Property* searchProperty(int id);
    bool removeProperty(int id);
    
    void loadSampleProperties();    
    bool markAsSold(int id);         
    
    void displayAllProperties();
    int getCount() const;
    
    std::string getPropertiesAsJSON();
};

#endif