#include "LogicHandler.h"
#include "GameMaster.h"

LogicHandler* LogicHandler::LogicHandlerInstance = nullptr;

LogicHandler* LogicHandler::GetInstance() {
  if (!LogicHandlerInstance) {
    LogicHandlerInstance = new LogicHandler();
  }
  return LogicHandlerInstance;
}
void LogicHandler::ChangeLogic(DefaultLogic* new_logic) {
  GameMaster* gm = GameMaster::GetInstance();
  gm->SetCurrentLogic(new_logic);
}
