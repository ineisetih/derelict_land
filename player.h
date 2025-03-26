#ifndef PLAYER
#define PLAYER

#include "inventory.h"

class Player{
private:
    float health;
    float damage;
    int level;
    float experience;
    PlayerInventory *inventory;
    static Player* player;
    Player();

public:
static Player* CreatePlayer();
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