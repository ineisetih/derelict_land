#include "BuyCommand.h"
#include "GameMaster.h"
#include "GetItemFromShop.h"
#include "PlayerGetItem.h"

#include <iostream>

#define DIFF_CHAR_INT 49

void BuyCommand::CommandExecute() {
  std::string user_input;
  std::cout << "What would you like to buy? Write a number of an item.\n";
  std::cin >> user_input;
  for (auto a : user_input) {
    if (a != ' ') {
      std::shared_ptr<IItem> item = GetItemFromShop::Execute(static_cast<int>(a) - DIFF_CHAR_INT);
      PlayerGetItem::Execute(item);
    }
  }
}
