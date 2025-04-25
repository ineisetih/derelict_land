#include "LogicHandler.h"
#include "MainMenuLogic.h"
#include "GameMaster.h"
#include "OnPlayerDeath.h"
#include <iostream>

void OnPlayerDeath::Execute() {
  std::cout << "YOU ARE DEAD" << std::endl;
  GameMaster::GetInstance()->SetPlayer(nullptr);
  GameMaster::GetInstance()->SetCurrentLogic(MainMenuLogic::GetInstance());
}
