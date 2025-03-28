
#include "UILogic.h"
#include "GameMaster.h"
#include "Player.h"
#include "TownLogic.h"


MainMenuLogic* MainMenuLogic::MainMenuLogicInstance = nullptr;

MainMenuLogic* MainMenuLogic::GetInstance() {
  if (!MainMenuLogicInstance) {
    MainMenuLogicInstance = new MainMenuLogic();
  }
  return MainMenuLogicInstance;
}
void NewGame::CommandExecute() {
  Player* player = Player::CreatePlayer();
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

void OpenShopCommand::CommandExecute(){
  GameMaster::GetInstance()->SetCurrentLogic(ShopLogic::GetInstance());
}


