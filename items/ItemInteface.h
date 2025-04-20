#ifndef ITEM_INTERFACE_H
#define ITEM_INTERFACE_H

#include <string>

enum ItemType { OneHandWeapon, BodyArmor, AttackGem };

class IItem {
 public:
  virtual std::string GetInfo() = 0;
  virtual ItemType GetType() = 0;
  virtual ~IItem() = default;
};

#endif  // ITEM_INTERFACE_H
