#ifndef ITEMSCPP
#define ITEMSCPP

#include "items.h"
#include <sstream>
#include <iostream>
#include <string>
#include <array>

// class WeaponGenerator{
//     public:
//     virtual Weapon* CreateWeapon(std::string name, float damage) = 0;
//     virtual ~WeaponGenerator() = default;
// };

// class SwordGenerator : public WeaponGenerator {
//     public:
//     Weapon* CreateWeapon(std::string name, float damage) override {
//         return new Sword(name, damage);
//     }
// };
// void Test(IItem* item){
//     item->GetInfo();
// }

std::string Gem::GetInfo() {
  return type + " gem (+" + std::to_string(bonus) + ")";
}

std::string Gem::GetType() {
  return type;
}

float Gem::GetBonus() {
  return bonus;
}

Weapon::~Weapon() {
  for (auto gem : gems) {
    delete gem;
  }
}

Armor::~Armor() {
  for (auto gem : gems) {
    delete gem;
  }
}


std::string Weapon::GetInfo() {
  std::stringstream ss;
  ss << name << " (Damage: " << damage << ", Slots: " << gems.size() << "/" << number_of_gem_slots << ")";
  return ss.str();
}

std::string Armor::GetInfo() {
  std::stringstream ss;
  ss << name << " (Defence: " << defence << ", Gems: " << gems.size() << "/" << number_of_gem_slots << ")";
  return ss.str();
}

std::string Sword::GetInfo() {
  std::stringstream ss;
  ss << "Sword " << name << " (Damage: " << damage << ", Gems: " << gems.size() << "/" << number_of_gem_slots << ")";
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

Sword::Sword(std::string name, float damage, int slots, std::vector<Gem*> gems) : Weapon(name, damage, slots) {
  for (auto gem : gems) {
    AddGem(gem);
  }
}

void Sword::AddGem(Gem* gem) {
  if (gems.size() < number_of_gem_slots) {
    gems.push_back(gem);
    damage += gem->GetBonus();
  }
}

void Sword::RemoveGem(Gem* gem) {
  auto it = std::find(gems.begin(), gems.end(), gem);
  if (it != gems.end()) {
    damage -= (*it)->GetBonus();
    gems.erase(it);
    delete gem;
  }
}


std::string Weapon::GetInfo() {
  std::stringstream ss;
  ss << name << " (Damage: " << damage << ", Slots: " << gems.size() << "/" << number_of_gem_slots << ")";
  return ss.str();
}

std::string Armor::GetInfo() {
  std::stringstream ss;
  ss << name << " (Defence: " << defence << ", Gems: " << gems.size() << "/" << number_of_gem_slots << ")";
  return ss.str();
}

std::string Sword::GetInfo() {
  std::stringstream ss;
  ss << "Sword " << name << " (Damage: " << damage << ", Gems: " << gems.size() << "/" << number_of_gem_slots << ")";
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

Sword::Sword(std::string name, float damage, int slots, std::vector<Gem*> gems) : Weapon(name, damage, slots) {
  for (auto gem : gems) {
    AddGem(gem);
  }
}

void Sword::AddGem(Gem* gem) {
  if (gems.size() < number_of_gem_slots) {
    gems.push_back(gem);
    damage += gem->GetBonus();
  }
}

void Sword::RemoveGem(Gem* gem) {
  auto it = std::find(gems.begin(), gems.end(), gem);
  if (it != gems.end()) {
    damage -= (*it)->GetBonus();
    gems.erase(it);
    delete gem;
  }
}

#endif  // ITEMSCPP