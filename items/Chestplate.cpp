#include "Chestplate.h"

// Конструктор класса Chestplate.
// Инициализирует нагрудник с именем, защитой и количеством слотов (по умолчанию 1), вызывая конструктор базового класса Armor.
Chestplate::Chestplate(std::string name, float defence, size_t slots = 1) : Armor(name, defence, slots) {};

// Возвращает тип предмета (для нагрудника это BodyArmor).
ItemType Chestplate::GetType() {
  return type;
}