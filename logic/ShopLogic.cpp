#include "ShopLogic.h"
#include "BuyCommand.h"
#include "ShowInventoryCommand.h"
#include "ExploreCommand.h"

#include <random>

ShopLogic* ShopLogic::ShopLogicInstance = nullptr;

// Возвращает единственный экземпляр класса ShopLogic (Singleton).
// При первом вызове инициализирует команды, доступные в магазине.
ShopLogic* ShopLogic::GetInstance() {
  if (!ShopLogicInstance) {
    ShopLogicInstance = new ShopLogic();
    ShopLogicInstance->AddCommand("buy", std::make_shared<BuyCommand>());
    ShopLogicInstance->AddCommand("explore", std::make_shared<ExploreCommand>());
    ShopLogicInstance->AddCommand("showInventory", std::make_shared<ShowInventoryCommand>());
  }
  return ShopLogicInstance;
}

// Возвращает список товаров, доступных в магазине.
std::vector<std::shared_ptr<IItem>> ShopLogic::GetCommoditys() {
  return commoditys;
}

// Вызывается при открытии магазина, генерирует товары и выводит их информацию.
void ShopLogic::OnShopOpen() {
  for (int i = 0; i < 3; i++){
  commoditys.push_back(ItemGenerator::GenerateItem());
  }

  for (auto item : commoditys) {
    std::cout << item->GetInfo() << " cost: " << std::rand() % 7 + 1 << std::endl;
  }
}
