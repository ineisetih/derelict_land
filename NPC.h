#ifndef NPC_H
#define NPC_H

#include "Character.h"

// NPC

class NPC : public Character {
 public:
  NPC(std::string name, float health, float damage);
  virtual void Interact();
};
class Merchant : public NPC {  // Торговец
 public:
  Merchant(std::string name, float health, float damage);
  void Interact() override;
};

#endif  // NPC_H