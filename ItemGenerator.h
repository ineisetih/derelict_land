#ifndef ITEM_GENERATOR_H
#define ITEM_GENERATOR_H

#include "items.h"
#include <memory>

class ItemGenerator {
 public:
  static std::shared_ptr<IItem> GenerateItem() {
    int choice = rand() % 3;
    switch (choice) {
      case 0:
        return std::make_shared<Sword>("Dropped Sword", 8.0f);
      case 1:
        return std::make_shared<Armor>("Dropped Armor", 5.0f, 0);
      case 2:
        return std::make_shared<Gem>("Random Gem", 2.0f);
      default:
        return nullptr;
    }
  }
};

#endif  // ITEM_GENERATOR_H