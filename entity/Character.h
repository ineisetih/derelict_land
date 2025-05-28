#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <iostream>
#include "InventoryInterfece.h"

class Character {
 protected:
  std::string name;
  float health;
  float damage;
  int level;
  IInventory* inventory;

 public:
  // Конструктор персонажа.
  Character(std::string name, float health, float damage);
  // Виртуальный деструктор по умолчанию.
  virtual ~Character() = default;

  // Виртуальная функция атаки на другого персонажа.
  virtual void Attack(Character* target);
  // Виртуальная функция получения урона.
  virtual void Take_Damage(float damage);
  // Виртуальная функция лечения.
  virtual void Heal(float heal);

  // Возвращает инвентарь персонажа.
  IInventory* GetInventory();
  // Возвращает имя персонажа.
  std::string GetName();
  // Возвращает текущее здоровье персонажа.
  float GetHealth();
  // Возвращает урон персонажа.
  float GetDamage();
};

#endif  // CHARACTER_H