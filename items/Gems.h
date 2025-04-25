#ifndef GEMS_H
#define GEMS_H

#include "ItemInteface.h"

class Gem : public IItem {
  ItemType type;
  std::string name;
  float bonus;

 public:
  Gem(std::string name, ItemType type, float bonus) : name(name), type(type), bonus(bonus) {};
  float GetBonus();
  ItemType GetType();
  std::string GetInfo() override;
};

#endif  // GEMS_H
