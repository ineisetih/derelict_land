#include "LogicHandler.h"

LogicHandler* LogicHandler::LogicHandlerInstance = nullptr;

LogicHandler* LogicHandler::GetInstance() {
  if (!LogicHandlerInstance) {
    LogicHandlerInstance = new LogicHandler();
  }
  return LogicHandlerInstance;
}
void LogicHandler::ChangeLogic(DefaultLogic* new_logic) {
  current_logic = new_logic;
}

DefaultLogic* LogicHandler::GetCurrentLogic() const {
    return current_logic;
}
