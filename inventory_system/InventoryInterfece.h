#ifndef INVENTORY
#define INVENTORY

#include "ItemInteface.h"
#include <string>
#include <vector>
#include <memory>

class IInventory {
 public:
  virtual std::string GetInfo() = 0;
  virtual void AddItem(IItem *item) = 0;
  virtual void RemoveItem(IItem *item) = 0;
  virtual ~IInventory() = default;
};

#endif  // INVENTORY