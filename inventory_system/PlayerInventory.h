#ifndef PLAYERINVENTORY_H
#define PLAYERINVENTORY_H

#include "InventoryInterfece.h"
#include <string>
#include <vector>
#include <memory>
#include <iostream>

class PlayerInventory : public IInventory {
 private:
  IItem *left_hand;
  IItem *right_hand;
  IItem *body;
  std::vector<IItem *> backpack;

 public:
  PlayerInventory();
  ~PlayerInventory() override;

  void AddItem(IItem *item) override;
  void RemoveItem(IItem *item) override;
  std::string GetInfo() override;
};

#endif  // PLAYERINVENTORY_H
