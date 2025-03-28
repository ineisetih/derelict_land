#include "CommandHandler.h"
#include "GameMaster.cpp"

void CommandHandler::ExecuteCommand(std::string& command) {
  GameMaster* gm = GameMaster::GetInstance();
  if (gm->GetCurrentLogic()) {
    gm->GetCurrentLogic()->DoCommand(command);
  }
}