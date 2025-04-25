#include "GetItemFromShop.h"
#include "GameMaster.h"

std::shared_ptr<IItem> GetItemFromShop::Execute(int index) {
  ;
  std::vector<std::shared_ptr<IItem>> commoditys = ShopLogic::GetInstance()->GetCommoditys();
  return commoditys[index];
}
