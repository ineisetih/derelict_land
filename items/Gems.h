#ifndef GEMS_H
#define GEMS_H

#include "ItemInteface.h"

class Gem : public IItem {
  ItemType type;
  std::string name;
  float bonus;

 public:
  // Конструктор камня.
  // name - имя камня.
  // type - тип камня (например, AttackGem).
  // bonus - числовое значение бонуса, предоставляемого камнем.
  Gem(std::string name, ItemType type, float bonus) : name(name), type(type), bonus(bonus) {};
  // Возвращает бонус, предоставляемый камнем.
  float GetBonus();
  // Возвращает тип камня.
  ItemType GetType();
  // Возвращает информацию о камне в виде строки.
  std::string GetInfo() override;
};

#endif  // GEMS_H
