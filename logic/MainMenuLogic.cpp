#include "MainMenuLogic.h"
#include "NewGame.h"
#include "LoadGameCommand.h"
#include "SavesListCommand.h"


MainMenuLogic* MainMenuLogic::MainMenuLogicInstance = nullptr;

MainMenuLogic* MainMenuLogic::GetInstance() {
  if (!MainMenuLogicInstance) {
    MainMenuLogicInstance = new MainMenuLogic();
    MainMenuLogicInstance->AddCommand("new game", std::make_shared<NewGame>());
    MainMenuLogicInstance->AddCommand("load", std::make_shared<LoadGameCommand>());
    MainMenuLogicInstance->AddCommand("list", std::make_shared<ListSavesCommand>());
  }
  return MainMenuLogicInstance;
}

