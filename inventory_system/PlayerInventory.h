#ifndef PLAYERINVENTORY_H
#define PLAYERINVENTORY_H

#include "InventoryInterfece.h"
#include <string>
#include <vector>
#include <memory>
#include <iostream>

class PlayerInventory : public IInventory {
 private:
  std::shared_ptr<IItem> left_hand;
  std::shared_ptr<IItem> right_hand;
  std::shared_ptr<IItem> body;
  std::vector<std::shared_ptr<IItem>> backpack;

 public:
  PlayerInventory();
  ~PlayerInventory() override;

  void AddItem(std::shared_ptr<IItem> item) override;
  void EquipWeapon(std::shared_ptr<IItem> weapon);
  void EquipArmor(std::shared_ptr<IItem> armor);
  void RemoveItem(std::shared_ptr<IItem> item) override;
  std::string GetInfo() override;
};

#endif  // PLAYERINVENTORY_H
