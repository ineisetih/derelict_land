#include "Enemy.h"
#include "ItemGenerator.h"

#include <memory>

Enemy::Enemy(std::string name, float health, float damage,float defence,float given_exp) 
: Character(name, health, damage),defence(defence),given_exp(given_exp) {
}

std::shared_ptr<IItem> Enemy::DropLoot() {
  std::cout << name << " dropped loot!\n";

  auto droppedItem = ItemGenerator::GenerateItem();
  std::cout << "Obtained: ";
  droppedItem->GetInfo();
  return droppedItem;
}

float Enemy::GetDefence() const {
  return defence;
}

float Enemy::GetGivenExp() const {
  return given_exp;
}