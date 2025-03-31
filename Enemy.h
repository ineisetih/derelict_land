#ifndef ENEMY_H
#define ENEMY_H

#include "Character.h"

class Enemy : public Character {
 public:
  Enemy(std::string name, float health, float damage);
  void DropLoot();
};

enum EnemyType { Goblin, Skeleton };

class EnemyFactory {
 public:
  static std::shared_ptr<Enemy> CreateEnemy(EnemyType type);
};

#endif  // ENEMY_H