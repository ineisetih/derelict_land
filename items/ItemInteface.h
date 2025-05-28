#ifndef ITEM_INTERFACE_H
#define ITEM_INTERFACE_H

#include <string>

enum ItemType { OneHandWeapon, BodyArmor, AttackGem };

class IItem {
 public:
  // Виртуальная функция для получения информации о предмете в виде строки.
  virtual std::string GetInfo() = 0;
  // Виртуальная функция для получения типа предмета.
  virtual ItemType GetType() = 0;
  // Виртуальный деструктор по умолчанию.
  virtual ~IItem() = default;
};

#endif  // ITEM_INTERFACE_H
