#include "CommandHandler.h"
#include "LogicHandler.h" 

CommandHandler* CommandHandler::instance = nullptr;

void CommandHandler::ExecuteCommand(std::string& command) {
  LogicHandler* lh = LogicHandler::GetInstance();
  if (lh->GetCurrentLogic()) {
    lh->GetCurrentLogic()->DoCommand(command);
  }
}

CommandHandler* CommandHandler::GetInstance() {
  if (!instance) {
    instance = new CommandHandler();
  }
  return instance;
}