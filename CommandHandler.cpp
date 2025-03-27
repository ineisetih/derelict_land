#include "CommandHandler.h"
#include "GameMaster.h"

void CommandHandler::ExecuteCommand(const std::string& command) {
  GameMaster* gm = GameMaster::GetInstance();
  if (gm->GetCurrentLogic()) {
    gm->GetCurrentLogic()->DoCommand(command);
  }
}