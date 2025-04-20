#include "FightLogic.h"
#include "ExitCommand.h"
#include "Player.h"
#include "GameMaster.h"
#include "ShowCommandsList.h"
#include "ShowPlayerStats.h"
#include "OnPlayerDeath.h"
#include "GiveLoot.h"

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

void FightLogic::StartFight() {
  try {
    Player* player = GameMaster::GetInstance()->GetPlayer();
    if (!player)
      throw std::runtime_error("Player not initialized");
    if (enemies.empty())
      throw std::runtime_error("No enemies in combat");
    std::vector<std::shared_ptr<IItem>> loot;
    while (player->GetHealth() > 0 && !enemies.empty()) {
      float player_damage = player->GetDamage();
      Enemy* current_enemy = enemies.front();
      float damage_to_enemy = player_damage - current_enemy->GetDefence();
      if (damage_to_enemy < 0) {
        damage_to_enemy = 0;
      }
      current_enemy->Take_Damage(damage_to_enemy);
      for (Enemy* enemy : enemies) {
        player->Take_Damage(enemy->GetDamage());
      }
      if (current_enemy->GetHealth() <= 0) {
        loot.push_back(current_enemy->DropLoot());
        player->AddExperience(current_enemy->GetGivenExp());
        RemoveEnemy(current_enemy);
      }
      if (player->GetHealth() <= 0) {
        OnPlayerDeath::Execute();
        return;
      }
    }
    std::cout << "Take your reward!\n";
    GiveLoot::Execute(loot);
  } catch (const std::exception& e) {
    std::cerr << "Combat error: " << e.what() << '\n';
    GameMaster::GetInstance()->SetCurrentLogic(TownLogic::GetInstance());
  }
}
