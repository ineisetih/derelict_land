#ifndef GEMS_H
#define GEMS_H

#include "ItemInteface.h"

class Gem : public IItem {
  std::string type;
  float bonus;

 public:
  Gem(std::string type, float bonus) : type(type), bonus(bonus) {};
  float GetBonus();
  std::string GetType();
  std::string GetInfo() override;
};

#endif // GEMS_H
