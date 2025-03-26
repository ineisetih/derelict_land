#include "NPC.h"
#include "items.h"
#include <iostream>
#include <vector>

Enemy::Enemy(std::string name, float health, float damage) : Character(name, health, damage) {}
void Enemy::DropLoot() {
    std::cout << name << " dropped loot!\n";
    std::vector<std::shared_ptr<IItem>> possibleLoot = {
        
    };
}


