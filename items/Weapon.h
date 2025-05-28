#ifndef WEAPON_H
#define WEAPON_H

#include "ItemInteface.h"
#include "Gems.h"
#include <vector>

class Weapon : public IItem {
 protected:
  std::string name;
  float damage;
  size_t number_of_gem_slots;
  std::vector<Gem*> gems;

 public:
  // Конструктор оружия.
  // name - имя оружия.
  // damage - базовый урон оружия.
  // slots - количество слотов для камней.
  Weapon(std::string name, float damage, size_t slots) : name(name), damage(damage), number_of_gem_slots(slots) {};

  // Деструктор. Освобождает память, занятую камнями.
  ~Weapon();
  // Возвращает информацию об оружии в виде строки.
  std::string GetInfo() override;
  // Возвращает урон оружия.
  float GetDamage();
  // Добавляет камень в оружие.
  void AddGem(Gem* gem);
  // Удаляет камень из оружия.
  void RemoveGem(Gem* gem);
};

#endif // WEAPON_H
