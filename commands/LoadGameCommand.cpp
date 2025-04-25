#include "LoadGameCommand.h"
#include "SaveManager.h"
#include "TownLogic.h"
#include "GameMaster.h"

#include <iostream>



void LoadGameCommand::CommandExecute() {
  std::cout << "Enter player name to load: ";
  std::string name;
  std::getline(std::cin, name);

  PlayerSave save = SaveManager::LoadGame(name);
  if (save.name.empty()) {
    std::cout << "Save not found!\n";
    return;
  }

  Player* player = Player::CreatePlayer(save.name, save.health, save.damage);
  player->AddExperience(save.experience - 100 * (save.level - 1));
  GameMaster::GetInstance()->SetPlayer(player);
  std::cout << "Game loaded for " << save.name << " (Level " << save.level << ")\n";
  GameMaster::GetInstance()->SetCurrentLogic(TownLogic::GetInstance());
}