#include "GameInitialisation.h"
#include "LogicHandler.h" 
#include "MainMenuLogic.h"
#include <iostream>

void GameInitialisation::StartGame() {
  LogicHandler::GetInstance()->ChangeLogic(MainMenuLogic::GetInstance()); 
  std::cout << "Game initialized successfully!" << '\n';
}
