#include "ExitCommand.h"
#include "SaveManager.h"
#include "Player.h"

#include <cstdlib>

void Exit::CommandExecute() {
  std::shared_ptr<Player> player = Player::GetInstance(); 
  if (player) {
    SaveManager::SaveGame(player);
    std::cout << "Game saved for player: " << player->GetName() << std::endl;
  } else {
    std::cerr << "No player instance to save." << std::endl;
  }
  std::cout << "Exiting game..." << std::endl;
  exit(0);
}
