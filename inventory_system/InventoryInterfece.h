#ifndef INVENTORY
#define INVENTORY

#include "ItemInteface.h"
#include <string>
#include <vector>
#include <memory>

class IInventory {
 public:
  virtual std::string GetInfo() = 0;
  virtual void AddItem(std::shared_ptr<IItem> item) = 0;
  virtual void RemoveItem(std::shared_ptr<IItem> item) = 0;
  virtual ~IInventory() = default;
}; 

#endif  // INVENTORY