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

FightLogic* FightLogic::GetInstance() {
  if (!MainFightLogicInstance) {
    MainFightLogicInstance = new FightLogic();
  }
  return MainFightLogicInstance;
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
  auto location = LocationGenerator::GenerateLocation();
  location->DisplayInfo();

  if (location->HasProperty("Enemies nearby")) {
    std::cout << "You encounter enemies!" << '\n';
    LogicHandler::GetInstance()->ChangeLogic(FightLogic::GetInstance());
  }
}

