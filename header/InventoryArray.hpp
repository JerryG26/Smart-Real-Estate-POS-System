#ifndef _INVENTORYARRAY_H_
#define _INVENTORYARRAY_H_
#include "Property.hpp"

class InventoryArray{
    private:
    static size_t totalStock;
    int capacity;
    Property *array;
    void resize();

    public:
    InventoryArray();
    ~InventoryArray();

    bool add(const Property &p);
    bool remove(int id);
    bool isEmpty()const;
};
#endif