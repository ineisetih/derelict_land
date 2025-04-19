#ifndef WEAPON_H
#define WEAPON_H

#include "ItemInteface.h"
#include "Gems.h"
#include <vector>

class Weapon : public IItem {
 protected:
  std::string name;
  float damage;
  size_t number_of_gem_slots;
  std::vector<Gem*> gems;

 public:
  Weapon(std::string name, float damage, size_t slots) : name(name), damage(damage), number_of_gem_slots(slots) {};

  ~Weapon() override;
  std::string GetInfo() override;
  void AddGem(Gem* gem);
  void RemoveGem(Gem* gem);
};

#endif // WEAPON_H
