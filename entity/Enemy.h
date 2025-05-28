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
  // Конструктор врага.
  Enemy(std::string name, float health, float damage, float defence, float given_exp);
  // Функция для получения добычи с врага.
  std::shared_ptr<IItem> DropLoot();
  // Возвращает значение защиты врага.
  float GetDefence() const;
  // Возвращает количество опыта, которое дает враг.
  float GetGivenExp() const;
};

enum EnemyType { Goblin, Skeleton };

#endif  // ENEMY_H