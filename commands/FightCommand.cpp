#include "FightCommand.h"
#include "FightLogic.h"

void FightCommand::CommandExecute() {
  FightLogic::GetInstance()->CreateEnemies();
  FightLogic::GetInstance()->StartFight();
}