#include "LogicHandler.h"
#include "MainMenuLogic.h"
#include "OnPlayerDeath.h"
#include <iostream>

void OnPlayerDeath::Execute() {
  std::cout << "YOU ARE DEAD" << std::endl;
  LogicHandler::GetInstance()->ChangeLogic(MainMenuLogic::GetInstance());
}



