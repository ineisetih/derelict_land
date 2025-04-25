#include "CommandHandler.h"

CommandHandler* CommandHandler::instance = nullptr;

void CommandHandler::ExecuteCommand(std::string& command) {
  GameMaster* gm = GameMaster::GetInstance();
  if (gm->GetCurrentLogic()) {
    gm->GetCurrentLogic()->DoCommand(command);
  }
}

CommandHandler* CommandHandler::GetInstance() {
  if (!instance) {
    instance = new CommandHandler();
  }
  return instance;
}