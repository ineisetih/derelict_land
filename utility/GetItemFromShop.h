#ifndef GET_ITEM_FROM_SHOP
#define GET_ITEM_FROM_SHOP

#include "ItemInteface.h"

#include <memory>

class GetItemFromShop {
 public:
  static std::shared_ptr<IItem> Execute(int item_index);
};

#endif  // GET_ITEM_FROM_SHOP