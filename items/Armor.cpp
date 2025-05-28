#include "Armor.h"
#include <sstream>
#include <algorithm>

// Конструктор класса Armor.
// Инициализирует броню с именем, защитой и количеством слотов для камней.
Armor::Armor(const std::string name, float defence, size_t slots = 0)
    : name(name), defence(defence), number_of_gem_slots(slots) {
}

// Деструктор класса Armor.
// Освобождает память, выделенную под камни.
Armor::~Armor() {
  for (auto gem : gems) {
    delete gem;
  }
}

// Возвращает информацию о броне в виде строки.
std::string Armor::GetInfo() {
  std::stringstream ss;
  ss << name << " (Defence: " << defence << ", Gems: " << gems.size() << "/" << number_of_gem_slots << ")";
  return ss.str();
}

// Добавляет камень в броню, если есть свободные слоты, и увеличивает защиту.
void Armor::AddGem(Gem* gem) {
  if (gems.size() < number_of_gem_slots) {
    gems.push_back(gem);
    defence += gem->GetBonus();
  }
}

// Удаляет указанный камень из брони, уменьшает защиту и освобождает память камня.
void Armor::RemoveGem(Gem* gem) {
  auto it = std::find(gems.begin(), gems.end(), gem);
  if (it != gems.end()) {
    defence -= (*it)->GetBonus();
    gems.erase(it);
    delete gem;
  }
}
