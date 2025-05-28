#include "FightLogic.h"
#include "ExitCommand.h"
#include "Player.h"
#include "LogicHandler.h"
#include "ShowPlayerStats.h"
#include "OnPlayerDeath.h"
#include "GiveLoot.h"
#include "EnemyFactory.h"
#include "FightCommand.h"
#include "EscapeCommand.h"
#include "ShowInventoryCommand.h"
#include "TownLogic.h"

#include <chrono>
#include <thread>

FightLogic* FightLogic::MainFightLogicInstance = nullptr;

// Возвращает единственный экземпляр класса FightLogic (Singleton).
// При первом вызове инициализирует команды, специфичные для боя.
FightLogic* FightLogic::GetInstance() {
  if (!MainFightLogicInstance) {
    MainFightLogicInstance = new FightLogic();
    MainFightLogicInstance->AddCommand("fight", std::make_shared<FightCommand>());
    MainFightLogicInstance->AddCommand("escape", std::make_shared<EscapeCommand>());
    MainFightLogicInstance->AddCommand("inventory", std::make_shared<ShowInventoryCommand>());

  }
  return MainFightLogicInstance;
}

// Добавляет врага в текущий бой.
void FightLogic::AddEnemy(std::shared_ptr<Enemy> enemy) {
  enemies.push_back(enemy);
}

// Удаляет врага из текущего боя.
void FightLogic::RemoveEnemy(std::shared_ptr<Enemy> enemy) {
  for (size_t i = 0; i < enemies.size(); i++) {
    if (enemies[i] == enemy) {
      enemies.erase(enemies.begin() + i);
    }
  }
}

// Возвращает вектор с врагами, участвующими в бою.
std::vector<std::shared_ptr<Enemy>>FightLogic::GetEnemies() {
  return enemies;
}

// Создает врагов для боя (в данном случае, одного Гоблина).
void FightLogic::CreateEnemies() {
  FightLogic::GetInstance()->AddEnemy(EnemyFactory::CreateEnemy(Goblin));
}

// Начинает и управляет процессом боя между игроком и врагами.
void FightLogic::StartFight() {
  try {
    std::shared_ptr<Player> player = Player::GetInstance();
    if (!player)
      throw std::runtime_error("Player not initialized");
    if (enemies.empty())
      throw std::runtime_error("No enemies in combat");
    std::vector<std::shared_ptr<IItem>> loot;
    while (player->GetHealth() > 0 && !enemies.empty()) {
      std::this_thread::sleep_for(std::chrono::seconds(1));
       float player_damage = player->GetDamage();
      auto current_enemy = enemies.front();
      float damage_to_enemy = player_damage - current_enemy->GetDefence();
      if (damage_to_enemy < 0) {
        damage_to_enemy = 0;
      }
      current_enemy->Take_Damage(damage_to_enemy);
      for (auto enemy : enemies) {
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
    LogicHandler::GetInstance()->ChangeLogic(TownLogic::GetInstance()); 
  } catch (const std::exception& e) {
    std::cerr << "Combat error: " << e.what() << '\n';
    LogicHandler::GetInstance()->ChangeLogic(TownLogic::GetInstance()); 
  }
}
