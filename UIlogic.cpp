#include "UILogic.h"
#include "GameMaster.h"
#include "Player.h"
#include "NPC.h"
#include "Enemy.h"


MainMenuLogic* MainMenuLogic::MainMenuLogicInstance = nullptr;
TownLogic* TownLogic::TownLogicInstance = nullptr;
FightLogic* FightLogic::MainFightLogicInstance = nullptr;

DefaultLogic::DefaultLogic() {
  AddCommand("exit", std::make_shared<Exit>());
  AddCommand("help", std::make_shared<ShowCommandsList>(this));
  AddCommand("stats", std::make_shared<ShowPlayerStats>());
}

MainMenuLogic* MainMenuLogic::GetInstance() {
  if (!MainMenuLogicInstance) {
    MainMenuLogicInstance = new MainMenuLogic();
    MainMenuLogicInstance->AddCommand("new game", std::make_shared<NewGame>());
  }
  return MainMenuLogicInstance;
}
void NewGame::CommandExecute() {
  GameMaster::GetInstance()->InitializePlayer();
  std::cout << "New game started! Player created." << std::endl;
  GameMaster::GetInstance()->SetCurrentLogic(TownLogic::GetInstance());
}

void DefaultLogic::DoCommand(std::string& console_command) {
  if (commands.find(console_command) != commands.end()) {
    commands[console_command]->CommandExecute();
  } else {
    std::cout << "Unknown command!" << std::endl;
  }
}

void DefaultLogic::AddCommand(std::string command_name, std::shared_ptr<ICommand> command) {
  commands[command_name] = command;
}

auto DefaultLogic::GetCommands() {
  return commands;
}

LogicHandler* LogicHandler::LogicHandlerInstance = nullptr;

LogicHandler* LogicHandler::GetInstance() {
  if (!LogicHandlerInstance) {
    LogicHandlerInstance = new LogicHandler();
  }
  return LogicHandlerInstance;
}
void LogicHandler::ChangeLogic(DefaultLogic* new_logic) {
  CurrentLogic = new_logic;
}

std::vector<Enemy*> FightLogic::GetEnemies() {
  return enemies;
}

void FightLogic::AddEnemy(Enemy* enemy) {
  if (enemy) {
    enemies.push_back(enemy);
  }
}

void FightLogic::RemoveEnemy(Enemy* enemy) {
  auto it = std::find(enemies.begin(), enemies.end(), enemy);
  if (it != enemies.end()) {
    enemies.erase(it);
    delete enemy;
  }
}

FightLogic* FightLogic::GetInstance() {
  if (!MainFightLogicInstance) {
    MainFightLogicInstance = new FightLogic();
    MainFightLogicInstance->AddCommand("fight", std::make_shared<FightCommand>());
  }
  return MainFightLogicInstance;
}

void FightLogic::ClearEnemies() {
  for (auto enemy : enemies) {
    delete enemy;
  }
  enemies.clear();
}

void FightLogic::StartFight() {
  try {
    Player* player = GameMaster::GetInstance()->GetPlayer();
    if (!player) throw std::runtime_error("Player not initialized");
    if (enemies.empty()) throw std::runtime_error("No enemies in combat");

    Enemy* currentEnemy = enemies[0];  // Берем первого врага
    if (!currentEnemy) throw std::runtime_error("Enemy is null");

    std::cout << "Fight started against " << currentEnemy->GetName() << "!\n";

    while (true) {
      // Ход игрока
      float playerDamage = player->GetDamage();
      currentEnemy->Take_Damage(playerDamage);
      std::cout << "You dealt " << playerDamage << " damage to " << currentEnemy->GetName() << "!\n";

      // Проверка, умер ли враг
      if (currentEnemy->GetHealth() <= 0) {
        std::cout << "You defeated " << currentEnemy->GetName() << "!\n";
        currentEnemy->DropLoot();
        RemoveEnemy(currentEnemy);

        // Добавляем опыт за победу
        player->AddExperience(30.0f);

        // Возвращаемся в город
        GameMaster::GetInstance()->SetCurrentLogic(TownLogic::GetInstance());
        return;
      }

      // Ход врага
      float enemyDamage = currentEnemy->GetDamage();
      player->Take_Damage(enemyDamage);
      std::cout << currentEnemy->GetName() << " dealt " << enemyDamage << " damage to you!\n";

      // Проверяем, умер ли игрок
      if (player->GetHealth() <= 0) {
        std::cout << "You were defeated! Game over.\n";
        exit(0);  // Завершаем игру
        return;
      }

      // Выводим текущее состояние
      std::cout << "Your health: " << player->GetHealth() << ", " << currentEnemy->GetName()
                << "'s health: " << currentEnemy->GetHealth() << "\n\n";
    }
  } catch (const std::exception& e) {
    std::cerr << "Combat error: " << e.what() << '\n';
    GameMaster::GetInstance()->SetCurrentLogic(TownLogic::GetInstance());
  }
}

TownLogic* TownLogic::GetInstance() {
  if (!TownLogicInstance) {
    TownLogicInstance = new TownLogic();
    TownLogicInstance->AddCommand("explore", std::make_shared<ExploreCommand>());
    TownLogicInstance->AddCommand("shop", std::make_shared<OpenShopCommand>());
    TownLogicInstance->AddCommand("inventory", std::make_shared<ShowInventoryCommand>());
  }
  return TownLogicInstance;
}

void OpenShopCommand::CommandExecute() {
  GameMaster::GetInstance()->SetCurrentLogic(ShopLogic::GetInstance());
}

void ShowInventoryCommand::CommandExecute() {
  Player* player = GameMaster::GetInstance()->GetPlayer();
  if (player) {
    std::cout << player->GetInventoryInfo() << '\n';
  } else {
    std::cout << "Player not initialized!" << '\n';
  }
}

ShopLogic* ShopLogic::ShopLogicInstance = nullptr;

ShopLogic* ShopLogic::GetInstance() {
  if (!ShopLogicInstance) {
    ShopLogicInstance = new ShopLogic();
  }
  return ShopLogicInstance;
}

void Exit::CommandExecute() {
  std::cout << "bye";
  exit(0);
}

ShowCommandsList::ShowCommandsList(DefaultLogic* logic) : logic(logic) {
}
void ShowCommandsList::CommandExecute() {
  std::cout << "Available commands:" << std::endl;
  for (const auto& pair : logic->GetCommands()) {
    std::cout << "- " << pair.first << std::endl;
  }
}

void ShowPlayerStats::CommandExecute() {
  if (GameMaster::GetInstance()->GetPlayer() != nullptr) {
    auto player = GameMaster::GetInstance()->GetPlayer();
    std::cout << "Hp: " << player->GetHealth() << std::endl;
    std::cout << "Damage: " << player->GetDamage() << std::endl;
    std::cout << "LVL: " << player->GetLevel() << std::endl;
    std::cout << "Exp: " << player->GetExperience() << std::endl;
  }
}

void ExploreCommand::CommandExecute() {
  try {
    auto location = LocationGenerator::GenerateLocation();
    location->DisplayInfo();

    if (location->HasProperty("Enemies nearby")) {
      std::cout << "You encounter enemies!" << '\n';
      auto fightLogic = FightLogic::GetInstance();
      fightLogic->ClearEnemies();

      EnemyType type = (rand() % 2 == 0) ? Goblin : Skeleton;
      auto enemy = EnemyFactory::CreateEnemy(type);
      if (!enemy)
        throw std::runtime_error("Failed to create enemy");

      fightLogic->AddEnemy(enemy.get());
      std::cout << "\nEncountered: " << enemy->GetName() << "\n";

      GameMaster::GetInstance()->SetCurrentLogic(fightLogic);
    }
  } catch (const std::exception& e) {
    std::cerr << "Exploration error: " << e.what() << '\n';
  }
}

