#include "ShopLogic.h"

ShopLogic* ShopLogic::ShopLogicInstance = nullptr;

ShopLogic* ShopLogic::GetInstance() {
  if (!ShopLogicInstance) {
    ShopLogicInstance = new ShopLogic();
  }
  return ShopLogicInstance;
}
