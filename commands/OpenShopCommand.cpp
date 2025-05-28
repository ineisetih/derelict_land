#include "OpenShopCommand.h"
#include "ShopLogic.h"
#include "LogicHandler.h" 

// Выполняет команду открытия магазина.
// Изменяет текущую игровую логику на логику магазина и вызывает метод OnShopOpen для генерации товаров.
void OpenShopCommand::CommandExecute() {
  LogicHandler::GetInstance()->ChangeLogic(ShopLogic::GetInstance()); 
  ShopLogic::GetInstance()->OnShopOpen();
}
