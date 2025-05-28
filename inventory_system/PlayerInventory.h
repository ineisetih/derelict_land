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
  void RemoveItem(std::shared_ptr<IItem> item) override;

  bool EquipWeapon(std::shared_ptr<IItem> weapon);
  bool EquipArmor(std::shared_ptr<IItem> armor);

  std::shared_ptr<IItem> GetLeftHand();
  std::shared_ptr<IItem> GetRightHand();
  std::shared_ptr<IItem> GetBody();
  std::vector<std::shared_ptr<IItem>> GetBackpack();

  std::string GetInfo() override;
};

#endif  // PLAYERINVENTORY_H
