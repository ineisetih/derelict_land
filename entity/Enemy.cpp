#include "Enemy.h"
#include "ItemGenerator.h"

Enemy::Enemy(std::string name, float health, float damage,float defence) : Character(name, health, damage),defence(defence) {
}

void Enemy::DropLoot() {
  std::cout << name << " dropped loot!\n";

  auto droppedItem = ItemGenerator::GenerateItem();
  std::cout << "Obtained: ";
  droppedItem->GetInfo();
}

float Enemy::GetDefence() const {
  return defence;
}