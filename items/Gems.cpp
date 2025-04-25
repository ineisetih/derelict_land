#include "Gems.h"

std::string Gem::GetInfo() {
  return name + " gem (+" + std::to_string(bonus) + ")";
}

ItemType Gem::GetType() {
  return type;
}

float Gem::GetBonus() {
  return bonus;
}
