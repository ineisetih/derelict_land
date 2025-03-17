#ifndef INVENTORY
#define INVENTORY

#include "items.h"
#include <string>
#include <vector>

class IInventory {
 public:
  virtual std::string GetInfo() = 0;
  virtual void AddItem(IItem *item) = 0;
  virtual void RemoveItem(IItem *item) = 0;
  virtual ~IInventory() = default;
};

class PlayerInventory : public IInventory {
 private:
  IItem *left_hand;
  IItem *right_hand;
  IItem *body;
  std::vector<IItem *> backpack;

 public:
  void AddItem(IItem *item) override;
  void RemoveItem(IItem *item) override;
  std::string GetInfo() override;
};

#endif