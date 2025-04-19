#ifndef LogicOfShop
#define LogicOfShop

#include "DefaultLogic.h"

class ShopLogic : public DefaultLogic {
 private:
  ShopLogic() = default;
  static ShopLogic *ShopLogicInstance;

 public:
  static ShopLogic *GetInstance();
};

#endif  // LogicOfShop
