#include "EnemyFactory.h"
#include "Enemy.h"
#include <random>

#define BASE_GOBLIN_HP 50.0f
#define BASE_SKELETON_HP 70.0f
#define BASE_GOBLIN_DMG 5.0f
#define BASE_SKELETON_DMG 8.0f
#define BASE_GOBLIN_DEF 1.0f
#define BASE_SKELETON_DEF 3.0f

std::shared_ptr<Enemy> EnemyFactory::CreateEnemy(EnemyType type) {
  switch (type) {
    case Goblin:
      return std::make_shared<Enemy>("Goblin", BASE_GOBLIN_HP, BASE_GOBLIN_DMG, BASE_GOBLIN_DEF);
    case Skeleton:
      return std::make_shared<Enemy>("Skeleton", BASE_SKELETON_HP, BASE_SKELETON_DMG, BASE_SKELETON_DEF);
    default:
      return nullptr;
  }
}
