#include "Weapon.h"
#include <sstream>
#include <algorithm>

Weapon::~Weapon() {
  for (auto gem : gems) {
    delete gem;
  }
}

std::string Weapon::GetInfo() {
  std::stringstream ss;
  ss << name << " (Damage: " << damage << ", Slots: " << gems.size() << "/" << number_of_gem_slots << ")";
  return ss.str();
}

void Weapon::AddGem(Gem* gem) {
  if (gems.size() < number_of_gem_slots) {
    gems.push_back(gem);
    damage += gem->GetBonus();
  }
}

void Weapon::RemoveGem(Gem* gem) {
  auto it = std::find(gems.begin(), gems.end(), gem);
  if (it != gems.end()) {
    damage -= (*it)->GetBonus();
    gems.erase(it);
    delete gem;
  }
}
