#ifndef NPC_H
#define NPC_H

#include "Character.h"

// NPC

class NPC : public Character {
 public:
  // Конструктор NPC.
  NPC(std::string name, float health, float damage);
  // Виртуальный метод взаимодействия с NPC.
  virtual void Interact();
};

#endif  // NPC_H