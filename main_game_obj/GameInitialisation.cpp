#include "GameInitialisation.h"
#include "GameMaster.h"
#include "MainMenuLogic.h"
#include <iostream>

void GameInitialisation::StartGame() {
  GameMaster* gm = GameMaster::GetInstance();
  gm->SetCurrentLogic(MainMenuLogic::GetInstance());
  std::cout << "Game initialized successfully!" << '\n';
}
