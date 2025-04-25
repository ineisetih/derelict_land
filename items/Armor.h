#ifndef ARMOR_H
#define ARMOR_H

#include "ItemInteface.h"
#include "Gems.h"
#include <vector>

class Armor : public IItem {
 protected:
  std::string name;
  std::vector<Gem*> gems;
  float defence;
  size_t number_of_gem_slots;

 public:
  std::string GetInfo() override;
  ~Armor();
  Armor(const std::string name, float defence, size_t slots);
  void AddGem(Gem* gem);
  void RemoveGem(Gem* gem);
};

#endif // ARMOR_H
