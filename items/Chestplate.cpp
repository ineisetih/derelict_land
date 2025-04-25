#include "Chestplate.h"

Chestplate::Chestplate(std::string name, float defence, size_t slots = 1) : Armor(name, defence, slots) {};

ItemType Chestplate::GetType() {
  return type;
}