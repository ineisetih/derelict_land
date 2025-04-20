#ifndef CHESTPLATE_H
#define CHESTPLATE_H

#include "Armor.h"

class Chestplate : public Armor {
  private:
  ItemType type = BodyArmor;
 public:
  Chestplate(std::string name, float defence, size_t slots);
ItemType GetType() override;
};

#endif // CHESTPLATE_H  