#include "ShopLogic.h"
#include "BuyCommand.h"
#include "ExploreCommand.h"

ShopLogic* ShopLogic::ShopLogicInstance = nullptr;

ShopLogic* ShopLogic::GetInstance() {
  if (!ShopLogicInstance) {
    ShopLogicInstance = new ShopLogic();
    ShopLogicInstance->AddCommand("buy", std::make_shared<BuyCommand>());
    ShopLogicInstance->AddCommand("explore", std::make_shared<ExploreCommand>());

  }
  return ShopLogicInstance;
}

std::vector<std::shared_ptr<IItem>> ShopLogic::GetCommoditys() {
  return commoditys;
}

void ShopLogic::OnShopOpen() {
  for (int i = 0; i < 3; i++){
  commoditys.push_back(ItemGenerator::GenerateItem());
  }

  for (auto item : commoditys) {
    std::cout << item->GetInfo() << std::endl;
  }
}
