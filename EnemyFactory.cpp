#include "Enemy.h"
#include <memory>

std::shared_ptr<Enemy> EnemyFactory::CreateEnemy(EnemyType type) {
  switch (type) {
    case Goblin:
      return std::make_shared<Enemy>("Goblin", 50.0f, 5.0f);
    case Skeleton:
      return std::make_shared<Enemy>("Skeleton", 70.0f, 8.0f);
    default:
      return nullptr;
  }
}