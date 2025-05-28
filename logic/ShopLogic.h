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
  // Статический метод для получения единственного экземпляра логики магазина.
  static ShopLogic *GetInstance();
  // Возвращает список товаров в магазине.
  std::vector<std::shared_ptr<IItem>> GetCommoditys();
  // Вызывается при открытии магазина для генерации товаров.
  void OnShopOpen();
};

#endif  // LogicOfShop
