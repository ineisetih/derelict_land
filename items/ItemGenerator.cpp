#include "ItemGenerator.h"
#include "Sword.h"
#include "Armor.h"
#include "Gems.h"
#include <random>

std::shared_ptr<IItem> ItemGenerator::GenerateItem() {
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
