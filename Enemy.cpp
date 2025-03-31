#include "Enemy.h"
#include "ItemGenerator.h"

Enemy::Enemy(std::string name, float health, float damage) : Character(name, health, damage) {
}

void Enemy::DropLoot() {
  std::cout << name << " dropped loot!\n";

  auto droppedItem = ItemGenerator::GenerateItem();
  std::cout << "Obtained: ";
  droppedItem->GetInfo();
}