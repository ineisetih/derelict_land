#include "NPC.h"
#include "items.h"
#include <iostream>
#include <vector>

Enemy::Enemy(std::string name, float health, float damage) : Character(name, health, damage) {}
void Enemy::DropLoot() {
    std::cout << name << " dropped loot!\n";
    std::vector<std::shared_ptr<IItem>> possibleLoot = {
        
    };
}

void NPC::Interact() {
  std::cout << name << " says: Hello, traveler!\n";
}

void Merchant::Interact() {
  std::cout << name << " says: Welcome to my shop! What would you like to buy?\n";
  // Здесь можно добавить логику открытия магазина
}
