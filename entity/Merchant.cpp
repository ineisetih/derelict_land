#include "Merchant.h"

// Конструктор класса Merchant.
// Инициализирует торговца с именем, здоровьем и уроном, вызывая конструктор базового класса NPC.
Merchant::Merchant(std::string name, float health, float damage) : NPC(name, health, damage) {
}

// Переопределенный метод взаимодействия с торговцем. Вызывает метод Interact базового класса.
void Merchant::Interact() {
  NPC::Interact();
}
