#include "NewGame.h"
#include "GameMaster.h"
#include "SaveManager.h"
#include <iostream>

void NewGame::CommandExecute() {
  std::string name;
  std::cout << "Enter player name: ";
  std::getline(std::cin, name);

  Player* player = Player::CreatePlayer(name, 100.0f, 10.0f);

  std::cout << "New game started for " << name << "!\n";
  GameMaster::GetInstance()->SetPlayer(player);
  GameMaster::GetInstance()->SetCurrentLogic(TownLogic::GetInstance());
}