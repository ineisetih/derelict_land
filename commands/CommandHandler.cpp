#include "CommandHandler.h"
#include "LogicHandler.h" 

CommandHandler* CommandHandler::instance = nullptr;

// Выполняет переданную команду, используя текущую активную логику игры.
void CommandHandler::ExecuteCommand(std::string& command) {
  LogicHandler* lh = LogicHandler::GetInstance();
  if (lh->GetCurrentLogic()) {
    lh->GetCurrentLogic()->DoCommand(command);
  }
}

// Возвращает единственный экземпляр класса CommandHandler (Singleton).
CommandHandler* CommandHandler::GetInstance() {
  if (!instance) {
    instance = new CommandHandler();
  }
  return instance;
}