#include "GameMaster.h"
#include "UILogic.h"

void GameInitialisation::StartGame() {
  GameMaster::GetInstance()->InitializePlayer("Hero", 100.0f, 10.0f);

  GameMaster::GetInstance()->SetCurrentLogic(MainMenuLogic::GetInstance());

  std::cout << "Game initialized successfully!" << std::endl;
}