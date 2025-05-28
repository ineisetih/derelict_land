#include "Gems.h"

// Возвращает информацию о камне в виде строки, включая его имя и бонус.
std::string Gem::GetInfo() {
  return name + " gem (+" + std::to_string(bonus) + ")";
}

// Возвращает тип камня.
ItemType Gem::GetType() {
  return type;
}

// Возвращает числовое значение бонуса, предоставляемого камнем.
float Gem::GetBonus() {
  return bonus;
}
