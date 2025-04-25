#ifndef LogicOfShop
#define LogicOfShop

#include "DefaultLogic.h"
#include "ItemInteface.h"
#include "ItemGenerator.h"

#include <vector>
#include <memory>

class ShopLogic : public DefaultLogic {
 private:
  ShopLogic() = default;
  std::vector<std::shared_ptr<IItem>> commoditys;
  static ShopLogic *ShopLogicInstance;

 public:
  static ShopLogic *GetInstance();
  std::vector<std::shared_ptr<IItem>> GetCommoditys();
  void OnShopOpen();
};

#endif  // LogicOfShop
