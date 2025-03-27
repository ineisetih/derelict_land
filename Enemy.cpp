#include "Enemy.h"
#include "ItemGenerator.h"

void Enemy::DropLoot() {
  std::cout << name << " dropped loot!\n";

  auto droppedItem = ItemGenerator::GenerateItem();
  std::cout << "Obtained: ";
  droppedItem->GetInfo();

  // Позже здесь нужно добавить предмет в инвентарь игрока
}