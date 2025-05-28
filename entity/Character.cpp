#include "Character.h"

// Конструктор класса Character.
// Инициализирует персонажа с именем, здоровьем и уроном.
Character::Character(std::string name, float health, float damage)
    : name(name), health(health), damage(damage), level(1), inventory(nullptr) {
}

// Атакует другую цель (персонажа).
void Character::Attack(Character* target) {
  if (target) {
    target->Take_Damage(damage);
    std::cout << name << " attacks " << target->GetName() << " for " << damage << " damage!\n";
  }
}

// Уменьшает здоровье персонажа на величину нанесенного урона.
void Character::Take_Damage(float damage) {
  health -= damage;
  if (health < 0) {
    health = 0;
  }
  std::cout << name << " takes " << damage << " damage. Health: " << health << "\n";
}

// Увеличивает здоровье персонажа на указанную величину.
void Character::Heal(float heal) {
  health += heal;
  std::cout << name << " heals for " << heal << ". Health: " << health << "\n";
}

// Возвращает имя персонажа.
std::string Character::GetName() {
  return name;
}

// Возвращает указатель на инвентарь персонажа.
IInventory* Character::GetInventory() {
  return inventory;
}

// Возвращает текущее здоровье персонажа.
float Character::GetHealth() {
  return health;
}
// Возвращает урон персонажа.
float Character::GetDamage() {
  return damage;
}