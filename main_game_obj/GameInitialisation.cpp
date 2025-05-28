#include "GameInitialisation.h"
#include "LogicHandler.h" 
#include "MainMenuLogic.h"
#include <iostream>

// Инициализирует и запускает игру.
// Устанавливает начальную игровую логику на главное меню.
void GameInitialisation::StartGame() {
  LogicHandler::GetInstance()->ChangeLogic(MainMenuLogic::GetInstance()); 
  std::cout << "Game initialized successfully!" << '\n';
}
