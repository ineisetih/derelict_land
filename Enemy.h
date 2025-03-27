#ifndef ENEMY_H
#define ENEMY_H

#include "Character.h"

class Enemy : public Character {
public:
    Enemy(std::string name, float health, float damage);
    void DropLoot(); // Метод для выпадения лута
};

#endif // ENEMY_H