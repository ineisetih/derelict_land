#include "NewGame.h"
#include "SaveManager.h"
#include "LogicHandler.h"
#include "TownLogic.h"
#include <iostream>
#include <memory> 

void NewGame::CommandExecute() {
  std::string name;
  std::cout << "Enter player name: ";
  std::getline(std::cin, name);

  std::shared_ptr<Player> player_sptr = Player::CreatePlayer(name, 100.0f, 10.0f); // Player::CreatePlayer now returns shared_ptr
  if (!player_sptr) {
    std::cerr << "Failed to create player." << std::endl;
    return;
  }
  SaveManager::SaveGame(player_sptr); 

  std::cout << "New game started for " << name << "!\n";
  LogicHandler::GetInstance()->ChangeLogic(TownLogic::GetInstance()); 
}