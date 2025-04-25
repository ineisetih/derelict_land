#ifndef SWORD_H
#define SWORD_H

#include "Weapon.h"
#include <vector>

class Sword : public Weapon {
  private:
  ItemType type = OneHandWeapon;
 public:
  Sword(std::string name, float damage, size_t slots = 1, std::vector<Gem*> gems = {});
  std::string GetInfo() override;
  ItemType GetType() override;
};

#endif // SWORD_H
