#include "Merchant.h"

Merchant::Merchant(std::string name, float health, float damage) : NPC(name, health, damage) {
}

void Merchant::Interact() {
  NPC::Interact();
}
