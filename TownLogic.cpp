#include "TownLogic.h"
#include "GameMaster.h"


TownLogic* TownLogic::GetInstance() {
  if (!TownLogicInstance) {
    TownLogicInstance = new TownLogic();
    TownLogicInstance->AddCommand("explore", std::make_shared<ExploreCommand>());
    TownLogicInstance->AddCommand("shop", std::make_shared<OpenShopCommand>());
  }
  return TownLogicInstance;
}