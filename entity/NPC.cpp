#include "NPC.h"
#include "Enemy.h"
#include <iostream>
#include <vector>

NPC::NPC(std::string name, float health, float damage) : Character(name, health, damage) {
}

void NPC::Interact() {
  std::cout << name << " says: Hello, traveler!\n";
}

