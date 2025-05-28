#include "NPC.h"
#include "Enemy.h"
#include <iostream>
#include <vector>

// Конструктор класса NPC.
// Инициализирует NPC с именем, здоровьем и уроном, вызывая конструктор базового класса Character.
NPC::NPC(std::string name, float health, float damage) : Character(name, health, damage) {
}

// Определяет стандартное взаимодействие с NPC.
void NPC::Interact() {
  std::cout << name << " says: Hello, traveler!\n";
}
