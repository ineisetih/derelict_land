#ifndef NPC_H
#define NPC_H

#include "Character.h"

// NPC

class NPC : public Character {
 public:
  NPC(std::string name, float health, float damage);
  virtual void Interact();
};

void NPC::Interact() {
  std::cout << name << " says: Hello, traveler!\n";
}

class Merchant : public NPC {  // Торговец
 public:
  Merchant(std::string name, float health, float damage);
  void Interact() override;
};

void Merchant::Interact() {
  std::cout << name << " says: Welcome to my shop! What would you like to buy?\n";
  // Здесь можно добавить логику открытия магазина
}

// ENEMYS

class Enemy : public Character {
 public:
  Enemy(std::string name, float health, float damage);
  void DropLoot();
};
#endif  // NPC_H