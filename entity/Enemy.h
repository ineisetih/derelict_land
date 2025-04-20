#ifndef ENEMY_H
#define ENEMY_H

#include "Character.h"
#include "ItemInteface.h"

#include <memory>

class Enemy : public Character {
 private:
  float defence;
  float given_exp;

 public:
  Enemy(std::string name, float health, float damage, float defence, float given_exp);
  std::shared_ptr<IItem> DropLoot();
  float GetDefence() const;
  float GetGivenExp() const;
};

enum EnemyType { Goblin, Skeleton };

#endif  // ENEMY_H