#include "EscapeCommand.h"
#include "LogicHandler.h"
#include "TownLogic.h"

void EscapeCommand::CommandExecute() {
  std::cout << "You escaped";
  LogicHandler::GetInstance()->ChangeLogic(TownLogic::GetInstance()); 
}