#include "FightCommand.h"
#include "FightLogic.h"

void FightCommand::CommandExecute() {
  FightLogic::GetInstance()->StartFight();
}