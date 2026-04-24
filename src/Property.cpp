#include "Property.hpp"
#include <iostream>
//Constructor
Property::Property(int id, std::string propertyType, std::string sector, double price): id{id}, propertyType{propertyType},sector{sector},price{price}{}

//Methodds
int Property::getId(){return id;}
std::string Property::getPropertyType(){return propertyType;}
std::string Property::getSector(){return sector;}
double Property::getPrice(){return price;}
void Property::setId(int id){this->id = id;}
void Property::setPropertyType(std::string type){this->propertyType = type;}
void Property::setSector(std::string sector){this->sector = sector;}
void Property::setPrice(double price){this->price = price;}
void Property::displayInfo(){
    std::cout<<"ID: "<<id<<"\nProperty Type: "<<propertyType<<"\nSector: "<<sector<<"\nPrice: "<<price<<std::endl;
}