#include "TownLogic.h"
#include "GameMaster.h"

TownLogic* TownLogic::TownLogicInstance = nullptr;

TownLogic* TownLogic::GetInstance() {
  if (!TownLogicInstance) {
    TownLogicInstance = new TownLogic();
    // Добавляем базовые команды для города
    TownLogicInstance->AddCommand("explore", std::make_shared<ExploreCommand>());
    TownLogicInstance->AddCommand("shop", std::make_shared<OpenShopCommand>());
  }
  return TownLogicInstance;
}