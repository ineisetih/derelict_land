
#include "UILogic.h"
#include "GameMaster.h"
#include "Player.h"

MainMenuLogic* MainMenuLogic::MainMenuLogicInstance = nullptr;
TownLogic* TownLogic::TownLogicInstance = nullptr;

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

void OpenShopCommand::CommandExecute() {
  GameMaster::GetInstance()->SetCurrentLogic(ShopLogic::GetInstance());
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

FightLogic* FightLogic::MainFightLogicInstance = nullptr;

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
  }
  return TownLogicInstance;
}

ShopLogic* ShopLogic::ShopLogicInstance = nullptr;

ShopLogic* ShopLogic::GetInstance() {
  if (!ShopLogicInstance) {
    ShopLogicInstance = new ShopLogic();
  }
  return ShopLogicInstance;
}
