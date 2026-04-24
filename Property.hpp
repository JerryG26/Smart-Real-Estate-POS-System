#ifndef _PROPERTY_H_
#define _PROPERTY_H_
#include <string>
class Property{
    private:
    int id;
    std::string propertyType;
    std::string sector;
    double price;

    public:
    Property(int id, std::string propertyType, std::string sector, double price);
    int getId();
    std::string getPropertyType();
    std::string getSector();
    double getPrice();
    void setId(int id);
    void setPropertyType(std::string type);
    void setSector(std::string sector);
    void setPrice(double price);
    void displayInfo();

};
#endif