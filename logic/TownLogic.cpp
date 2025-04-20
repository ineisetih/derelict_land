#include "TownLogic.h"
#include "ExploreCommand.h"
#include "OpenShopCommand.h"
#include "ShowInventoryCommand.h"
#include "FightCommand.h"

TownLogic* TownLogic::TownLogicInstance = nullptr;

TownLogic* TownLogic::GetInstance() {
  if (!TownLogicInstance) {
    TownLogicInstance = new TownLogic();
    TownLogicInstance->AddCommand("explore", std::make_shared<ExploreCommand>());
    TownLogicInstance->AddCommand("fight", std::make_shared<FightCommand>());
    TownLogicInstance->AddCommand("shop", std::make_shared<OpenShopCommand>());
    TownLogicInstance->AddCommand("inventory", std::make_shared<ShowInventoryCommand>());
  }
  return TownLogicInstance;
}
