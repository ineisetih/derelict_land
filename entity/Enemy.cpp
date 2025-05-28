#include "Enemy.h"
#include "ItemGenerator.h"

#include <memory>

// Конструктор класса Enemy.
// Инициализирует врага с именем, здоровьем, уроном, защитой и количеством опыта за победу.
Enemy::Enemy(std::string name, float health, float damage,float defence,float given_exp) 
: Character(name, health, damage),defence(defence),given_exp(given_exp) {
}

// Отвечает за выпадение добычи из врага.
std::shared_ptr<IItem> Enemy::DropLoot() {
  std::cout << name << " dropped loot!\n";

  auto droppedItem = ItemGenerator::GenerateItem();
  std::cout << "Obtained: ";
  droppedItem->GetInfo();
  return droppedItem;
}

// Возвращает значение защиты врага.
float Enemy::GetDefence() const {
  return defence;
}

// Возвращает количество опыта, получаемого за победу над врагом.
float Enemy::GetGivenExp() const {
  return given_exp;
}