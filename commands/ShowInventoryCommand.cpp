#include "ShowInventoryCommand.h"
#include "Player.h"

void ShowInventoryCommand::CommandExecute() {
  std::shared_ptr<Player> player = Player::GetInstance();
  if (player) {
    std::cout << player->GetInventoryInfo() << '\n';
  } else {
    std::cout << "Player not initialized!" << '\n';
  }
}
