#include "GetItemFromShop.h"
#include "ShopLogic.h"

#include <vector>

std::shared_ptr<IItem> GetItemFromShop::Execute(int index) {
  ;
  std::vector<std::shared_ptr<IItem>> commoditys = ShopLogic::GetInstance()->GetCommoditys();
  return commoditys[index];
}
