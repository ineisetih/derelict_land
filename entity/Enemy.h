#ifndef ENEMY_H
#define ENEMY_H

#include "Character.h"

class Enemy : public Character {
 public:
  Enemy(std::string name, float health, float damage);
  void DropLoot();
};

enum EnemyType { Goblin, Skeleton };

#endif  // ENEMY_H