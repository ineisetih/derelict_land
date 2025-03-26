#include "UIlogic.h"
#include "player.h"

#include <iostream>
#include <list>

void DefualtLogic::DoCommand(std::string& console_command) {
  std::shared_ptr<ICommand> command;

  if (commands.find(console_command) != commands.end()) {
    command = commands[console_command];
  } else {
    std::string str;
    std::cin >> str;
    DoCommand(str);
    return;
  }
  command->CommandExecute();
}

MainMenuLogic* MainMenuLogic::GetInstance() {
  if (MainMenuLogicInstance == nullptr) {
    MainMenuLogicInstance = new MainMenuLogic; 
  }
  return MainMenuLogicInstance;
}

TownLogic* TownLogic::GetInstance() {
  if (TownLogicInstance == nullptr) {
    TownLogicInstance = new TownLogic;
  }
  return TownLogicInstance;
}

void DefualtLogic::AddComand(std::string& command_name, std::shared_ptr<ICommand> command) {
  commands[command_name] = command;
}

void NewGame::CommandExecute() {
  Player* player = Player::CreatePlayer();
  TownLogic* town_logic = TownLogic::GetInstance();
};