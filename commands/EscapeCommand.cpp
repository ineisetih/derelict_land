#include "EscapeCommand.h"
#include "GameMaster.h"
#include "TownLogic.h"

void EscapeCommand::CommandExecute() {
  std::cout << "You escaped" << std::endl;
  GameMaster::GetInstance()->SetCurrentLogic(TownLogic::GetInstance());
}