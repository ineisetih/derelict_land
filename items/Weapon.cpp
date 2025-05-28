#include "Weapon.h"
#include <sstream>
#include <algorithm>

// Деструктор класса Weapon.
// Освобождает память, выделенную для каждого камня (gem) в оружии.
Weapon::~Weapon() {
  for (auto gem : gems) {
    delete gem;
  }
}

// Возвращает строковое представление информации об оружии,
// включая его имя, урон и количество занятых/всего слотов для камней.
std::string Weapon::GetInfo() {
  std::stringstream ss;
  ss << name << " (Damage: " << damage << ", Slots: " << gems.size() << "/" << number_of_gem_slots << ")";
  return ss.str();
}

// Добавляет камень (gem) в оружие, если количество камней не превышает доступные слоты.
// При добавлении камня, его бонус к урону прибавляется к общему урону оружия.
void Weapon::AddGem(Gem* gem) {
  if (gems.size() < number_of_gem_slots) {
    gems.push_back(gem);
    damage += gem->GetBonus();
  }
}

// Возвращает текущий урон оружия.
// Примечание: в текущей реализации суммирует базовый урон и бонусы от камней дважды при расчете, но возвращает только базовый урон. Следует исправить.
float Weapon::GetDamage() {
  float temp = 0;
  temp += damage;
  for (auto gem : gems) {
    temp += gem->GetBonus();
  }
  return damage;
}

// Удаляет указанный камень (gem) из оружия.
// Уменьшает общий урон оружия на величину бонуса удаляемого камня и освобождает память, занятую камнем.
void Weapon::RemoveGem(Gem* gem) {
  auto it = std::find(gems.begin(), gems.end(), gem);
  if (it != gems.end()) {
    damage -= (*it)->GetBonus();
    gems.erase(it);
    delete gem;
  }
}
