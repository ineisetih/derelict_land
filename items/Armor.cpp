#include "Armor.h"
#include <sstream>
#include <algorithm>

Armor::Armor(const std::string name, float defence, size_t slots)
    : name(name), defence(defence), number_of_gem_slots(slots) {
}

Armor::~Armor() {
  for (auto gem : gems) {
    delete gem;
  }
}

std::string Armor::GetInfo() {
  std::stringstream ss;
  ss << name << " (Defence: " << defence << ", Gems: " << gems.size() << "/" << number_of_gem_slots << ")";
  return ss.str();
}

void Armor::AddGem(Gem* gem) {
  if (gems.size() < number_of_gem_slots) {
    gems.push_back(gem);
    defence += gem->GetBonus();
  }
}

void Armor::RemoveGem(Gem* gem) {
  auto it = std::find(gems.begin(), gems.end(), gem);
  if (it != gems.end()) {
    defence -= (*it)->GetBonus();
    gems.erase(it);
    delete gem;
  }
}
