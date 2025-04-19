#include "FightLogic.h"
#include "ExitCommand.h"
#include "ShowCommandsList.h"
#include "ShowPlayerStats.h"

FightLogic* FightLogic::MainFightLogicInstance = nullptr;

FightLogic* FightLogic::GetInstance() {
  if (!MainFightLogicInstance) {
    MainFightLogicInstance = new FightLogic();
  }
  return MainFightLogicInstance;
}

void FightLogic::AddEnemy(Enemy* enemy) {
  enemies.push_back(enemy);
}

void FightLogic::RemoveEnemy(Enemy* enemy) {
  for (size_t i = 0; i < enemies.size(); i++) {
    if (enemies[i] == enemy) {
      enemies.erase(enemies.begin() + i);
    }
  }
}

std::vector<Enemy*> FightLogic::GetEnemies() {
  return enemies;
}
