#ifndef NPC_H
#define NPC_H

#include "Character.h"

// NPC

class NPC : public Character {
 public:
  NPC(std::string name, float health, float damage);
  virtual void Interact();
};

#endif  // NPC_H