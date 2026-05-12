#include "InventoryArray.hpp"


InventoryArray::InventoryArray():capacity{5}{
    array = new Property[capacity];
}

InventoryArray::~InventoryArray(){
    delete[] array;
}

size_t InventoryArray::totalStock{0};

bool InventoryArray::add(const Property &p){
    if(capacity == 5){
        resize();
    }
    array[totalStock++] = p;
}
bool InventoryArray::remove(int id){
    int index{0};
    bool isFound{false};
    for(int i{0}; i < totalStock; i++){
        if(array[i].getId() == id){
            index = i;
            isFound = true;
            break;
        }
    }
    if(isFound){
        for(int i{index}; i < totalStock-1; i++){
            array[i] = array[i+1];
        }
        totalStock--;
        return true;
    }
    return false;
}
bool InventoryArray::isEmpty()const{
    return totalStock == 0;
}

void InventoryArray::resize(){
    int newCapacity = capacity*2;
    Property *newArray = new Property[newCapacity];

    for(int i{0}; i < capacity; i++){
        newArray[i] = array[i];
    }
    delete[] array;
    array = newArray;
    capacity = newCapacity;
}