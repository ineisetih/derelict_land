#include "FightCommand.h"
#include "FightLogic.h"

void FightCommand::CommandExecute() {
  // Создает врагов для боя.
  FightLogic::GetInstance()->CreateEnemies();
  // Начинает бой.
  FightLogic::GetInstance()->StartFight();
}