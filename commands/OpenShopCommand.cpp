#include "OpenShopCommand.h"
#include "ShopLogic.h"
#include "LogicHandler.h" 

void OpenShopCommand::CommandExecute() {
  LogicHandler::GetInstance()->ChangeLogic(ShopLogic::GetInstance()); 
  ShopLogic::GetInstance()->OnShopOpen();
}
