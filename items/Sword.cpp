#include "Sword.h"
#include <sstream>

Sword::Sword(std::string name, float damage, size_t slots, std::vector<Gem*> gems) : Weapon(name, damage, slots) {
  for (auto gem : gems) {
    AddGem(gem);
  }
}

std::string Sword::GetInfo() {
  std::stringstream ss;
  ss << "Sword " << name << " (Damage: " << damage << ", Gems: " << gems.size() << "/" << number_of_gem_slots << ")";
  return ss.str();
}
