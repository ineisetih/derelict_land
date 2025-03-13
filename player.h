#ifndef PLAYER
#define PLAYER

#include "inventory.h"

class Player{
private:
    float health;
    float damage;
    int level;
    float experience;
    IInventory *inventory;
    static bool isHeroCreated;
    

public:
Player();
Player(float health, float damage) : health(health), damage(damage), level(0), experience(0) {}
float GetHealth();
float GetDamage();
int GetLevel();
float GetExperience();
void SetHealth(float health);
void SetDamage(float damage);
void AddLevel(int level);
void AddExperience(float experience);
};

#endif