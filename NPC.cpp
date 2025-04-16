#include "Enemy.h"
#include "NPC.h"
#include "items.h"
#include <iostream>
#include <vector>

Enemy::Enemy(std::string name, float health, float damage) : Character(name, health, damage) {};

void NPC::Interact() {
  std::cout << name << " says: Hello, traveler!\n";
}

void Merchant::Interact() {
  std::cout << name << " says: Welcome to my shop! What would you like to buy?\n";
  // Здесь можно добавить логику открытия магазина
}
