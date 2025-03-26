#include "Character.h"

Character::Character(std::string name, float health, float damage)
    : name(name), health(health), damage(damage), level(1), inventory(nullptr) {
}

void Character::Attack(Character* target) {
  if (target) {
    target->Take_Damage(damage);
    std::cout << name << " attacks " << target->GetName() << " for " << damage << " damage!\n";
  }
}

void Character::Take_Damage(float damage) {
  health -= damage;
  if (health < 0) {
    health = 0;
  }
  std::cout << name << " takes " << damage << " damage. Health: " << health << "\n";
}

void Character::Heal(float heal) {
  health += heal;
  std::cout << name << " heals for " << heal << ". Health: " << health << "\n";
}

std::string Character::GetName() {
  return name;
}
float Character::GetHealth() {
  return health;
}
float Character::GetDamage() {
  return damage;
}