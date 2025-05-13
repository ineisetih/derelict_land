#include "LoadGameCommand.h"
#include "SaveManager.h"
#include "TownLogic.h"
#include "GameMaster.h"

#include <iostream>



void LoadGameCommand::CommandExecute() {
  std::cout << "Enter player name to load: ";
  std::string name;
  std::getline(std::cin, name);

  std::shared_ptr<Player> save = SaveManager::LoadGame(name);
//   if (save.name.empty()) {
//       std::cout << "Save not found!\n";
//       return;
//   }

//   Player* player = Player::CreatePlayer(save.name, save.health, save.damage);
//   player->AddExperience(save.experience - 100 * (save.level - 1));

//   if (!save.equippedItems.empty()) {
//       if (save.equippedItems.size() > 0 && save.equippedItems[0] != "Empty") {
//           player->EquipWeapon(SaveManager::ParseItem(save.equippedItems[0]));
//       }
//       if (save.equippedItems.size() > 1 && save.equippedItems[1] != "Empty") {
//       }
//       if (save.equippedItems.size() > 2 && save.equippedItems[2] != "Empty") {
//           player->EquipArmor(SaveManager::ParseItem(save.equippedItems[2]));
//       }
//   }

//   for (const auto& itemStr : save.backpackItems) {
//       player->AddItemToBackpack(SaveManager::ParseItem(itemStr));
//   }
//   std::cout << "Game loaded for " << save.name << " (Level " << save.level << ")\n";
  GameMaster::GetInstance()->SetCurrentLogic(TownLogic::GetInstance());
}