#ifndef ENEMY_H
#define ENEMY_H

#include "Character.h"

class Enemy : public Character {
  private:
  float defence;
 public:
  Enemy(std::string name, float health, float damage, float defence)
      : Character(name, health, damage) {};
  void DropLoot();
  float GetDefence() const;
};

enum EnemyType { Goblin, Skeleton };

#endif  // ENEMY_H