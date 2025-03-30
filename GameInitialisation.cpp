#include "GameInitialisation.h"
#include "GameMaster.h"
#include "UILogic.h"

void GameInitialisation::StartGame() {
  GameMaster* gm = GameMaster::GetInstance();
  gm->SetCurrentLogic(MainMenuLogic::GetInstance());
  std::cout << "Game initialized successfully!" << '\n';
}

//void GameInitialisation::StartGame() {
//  auto* logic = MainMenuLogic::GetInstance();
//  logic->AddCommand("explore", std::make_shared<ExploreCommand>());
//
//  GameMaster::GetInstance()->SetCurrentLogic(logic);
//  std::cout << "Type 'explore' to start journey or 'exit' to quit\n";
