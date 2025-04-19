#ifndef ITEM_GENERATOR_H
#define ITEM_GENERATOR_H

#include "ItemInteface.h"
#include <memory>
#include <cstdlib>

class ItemGenerator {
 public:
  static std::shared_ptr<IItem> GenerateItem();
};

#endif  // ITEM_GENERATOR_H
