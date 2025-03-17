// ЭТО КЛАСС ОБЩИЙ
#ifndef CHARACTER_H
#define CHARACTER_H

#include "items.h"
#include "inventory.h"
#include <string>
#include <iostream>

class Character {
 protected:
  std::string name;
  float health;
  float damage;
  int level; 
  IInventory *inventory;

 public:
  Character(std::string name, float health, float damage);
  virtual ~Character() = default;

  virtual void Attack(Character* target);
  virtual void Take_Damage(float damage);
  virtual void Heal(float heal);

  std::string GetName();
  float GetHealth();
  float GetDamage();  
  
};

#endif // CHARACTER_H