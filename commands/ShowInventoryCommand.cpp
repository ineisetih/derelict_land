#include "ShowInventoryCommand.h"
#include "GameMaster.h"
#include "Player.h"

void ShowInventoryCommand::CommandExecute() {
  Player* player = GameMaster::GetInstance()->GetPlayer();
  if (player) {
    std::cout << player->GetInventoryInfo() << '\n';
  } else {
    std::cout << "Player not initialized!" << '\n';
  }
}
