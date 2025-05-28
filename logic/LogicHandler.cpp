#include "LogicHandler.h"

LogicHandler* LogicHandler::LogicHandlerInstance = nullptr;

// Возвращает единственный экземпляр класса LogicHandler (Singleton).
LogicHandler* LogicHandler::GetInstance() {
  if (!LogicHandlerInstance) {
    LogicHandlerInstance = new LogicHandler();
  }
  return LogicHandlerInstance;
}
// Изменяет текущую игровую логику на новую.
void LogicHandler::ChangeLogic(DefaultLogic* new_logic) {
  current_logic = new_logic;
}

// Возвращает указатель на текущую активную игровую логику.
DefaultLogic* LogicHandler::GetCurrentLogic() const {
    return current_logic;
}
