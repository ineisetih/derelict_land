#include "ItemGenerator.h"
#include "Sword.h"
#include "Chestplate.h"
#include "Gems.h"
#include <random>

#define TEMPLATE_1 8.0f
#define TEMPLATE_2 5.0f
#define TEMPLATE_3 2.0f
#define TEMPLATE_4 0
#define TEMPLATE_5 AttackGem

std::shared_ptr<IItem> ItemGenerator::GenerateItem() {
  int choice = rand() % 3;
  switch (choice) {
    case 0:
      return std::make_shared<Sword>("Dropped Sword", TEMPLATE_1);
    case 1:
      return std::make_shared<Chestplate>(std::string("Dropped Chestplate"), TEMPLATE_2, TEMPLATE_4);
    case 2:
      return std::make_shared<Gem>("Random Gem", TEMPLATE_5, TEMPLATE_3);
    default:
      return nullptr;
  }
}
