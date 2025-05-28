#include "EscapeCommand.h"
#include "LogicHandler.h"
#include "TownLogic.h"

// Выполняет команду побега из текущей ситуации (например, боя).
// Выводит сообщение о побеге и изменяет игровую логику на логику города.
void EscapeCommand::CommandExecute() {
  std::cout << "You escaped";
  LogicHandler::GetInstance()->ChangeLogic(TownLogic::GetInstance()); 
}