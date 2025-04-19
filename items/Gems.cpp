#include "Gems.h"

std::string Gem::GetInfo() {
  return type + " gem (+" + std::to_string(bonus) + ")";
}

std::string Gem::GetType() {
  return type;
}

float Gem::GetBonus() {
  return bonus;
}
