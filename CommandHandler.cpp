#include "CommandHandler.h"
#include "GameMaster.h"

CommandHandler* CommandHandler::instance = nullptr;

void CommandHandler::ExecuteCommand(std::string& command) {
  GameMaster* gm = GameMaster::GetInstance();
  if (gm->GetCurrentLogic()) {
    gm->GetCurrentLogic()->DoCommand(command);
  }
}