#include "OpenShopCommand.h"
#include "ShopLogic.h"
#include "GameMaster.h"

void OpenShopCommand::CommandExecute() {
  GameMaster::GetInstance()->SetCurrentLogic(ShopLogic::GetInstance());
}
