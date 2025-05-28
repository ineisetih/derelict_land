#ifndef CHESTPLATE_H
#define CHESTPLATE_H

#include "Armor.h"

class Chestplate : public Armor {
  private:
  ItemType type = BodyArmor;
 public:
  // Конструктор нагрудника.
  // name - имя нагрудника.
  // defence - базовое значение защиты.
  // slots - количество слотов для камней.
  Chestplate(std::string name, float defence, size_t slots);
  // Возвращает тип предмета (BodyArmor).
ItemType GetType() override;
};

#endif // CHESTPLATE_H  