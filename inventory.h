#ifndef INVENTORY
#define INVENTORY

#include "items.h"
#include <string>

class IInventory {
    public:
    virtual std::string GetInfo() = 0;
    virtual void AddItem(IItem* item) = 0;
    virtual void RemoveItem(IItem* item) = 0;
    virtual ~IInventory() = default;
};




#endif