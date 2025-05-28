#include "LoadGameCommand.h"
#include "SaveManager.h"
#include "TownLogic.h"
#include "LogicHandler.h"

#include <iostream>

void LoadGameCommand::CommandExecute() {
  std::cout << "Enter player name to load: ";
  std::string name;
  std::getline(std::cin, name);

  std::shared_ptr<Player> player = SaveManager::LoadGame(name);
  if (!player) {
    std::cerr << "Load failed: player not found in database." << std::endl;
    return;
  }

  std::cout << "Loaded player: " << name << " (Level " << player->GetLevel() << ")" << std::endl;
  std::cout << "stage 1\n";
  LogicHandler::GetInstance()->ChangeLogic(TownLogic::GetInstance());
  std::cout << "stage 2\n";
}
