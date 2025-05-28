#include "Sword.h"
#include <sstream>

// Конструктор класса Sword.
// Инициализирует меч с именем, уроном, количеством слотов и списком камней, вызывая конструктор базового класса Weapon.
Sword::Sword(std::string name, float damage, size_t slots, std::vector<Gem*> gems) : Weapon(name, damage, slots) {
  for (auto gem : gems) {
    AddGem(gem);
  }
}

// Возвращает информацию о мече в виде строки, включая его тип, имя, урон и количество камней.
std::string Sword::GetInfo() {
  std::stringstream ss;
  ss << "Sword " << name << " (Damage: " << damage << ", Gems: " << gems.size() << "/" << number_of_gem_slots << ")";
  return ss.str();
}
// Возвращает тип предмета (для меча это OneHandWeapon).
ItemType Sword::GetType() {
  return type;
}
