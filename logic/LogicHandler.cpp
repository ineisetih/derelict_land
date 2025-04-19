#include "LogicHandler.h"

LogicHandler* LogicHandler::LogicHandlerInstance = nullptr;

LogicHandler* LogicHandler::GetInstance() {
  if (!LogicHandlerInstance) {
    LogicHandlerInstance = new LogicHandler();
  }
  return LogicHandlerInstance;
}
void LogicHandler::ChangeLogic(DefaultLogic* new_logic) {
  CurrentLogic = new_logic;
}
