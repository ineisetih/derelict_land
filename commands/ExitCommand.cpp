#include "ExitCommand.h"
#include "SaveManager.h"
#include "Player.h"
#include "GameMaster.h"
#include <process.h>

void Exit::CommandExecute() {
  Player* player = GameMaster::GetInstance()->GetPlayer();
  SaveManager::SaveGame(player);
  exit(0);
}
