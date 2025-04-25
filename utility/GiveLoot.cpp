#include "GiveLoot.h"
#include "PlayerGetItem.h"

#include <iostream>
#include <string>

#define DIFF_CHAR_INT 49

void GiveLoot::Execute(std::vector<std::shared_ptr<IItem>> loot) {
  try {
    int i = 1;
    for (auto item : loot) {
      std::cout << i++ << ". " << item->GetInfo() << std::endl;
    }
    std::cout << "To take reward type numbers of items\n";
    std::string user_input;
    std::cin >> user_input;
    for (auto a : user_input) {  
      if (a != ' ') {
        std::cout << static_cast<int>(a) - 1 << std::endl;
        std::cout << loot[static_cast<int>(a) - DIFF_CHAR_INT]->GetInfo() << std::endl;
        PlayerGetItem::Execute(loot[static_cast<int>(a) - DIFF_CHAR_INT]);
      }
    }
  } catch (const std::exception& e) {
    std::cerr << "Loot error: " << e.what() << '\n';
  }
}
