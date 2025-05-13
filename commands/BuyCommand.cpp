#include "BuyCommand.h"
#include "GameMaster.h"
#include "GetItemFromShop.h"
#include "PlayerGetItem.h"

#include <iostream>

#define DIFF_CHAR_INT 49

void BuyCommand::CommandExecute() {
  std::string user_input;
  std::cout << "What would you like to buy? Write a number of an item.\n";
  std::getline(std::cin, user_input);
  for (auto a : user_input) {
    if (a != ' ' && a != '\n') {
      int user_input_int = static_cast<int>(a) - DIFF_CHAR_INT;
      if (isdigit(a) && user_input_int < ShopLogic::GetInstance()->GetCommoditys().size() && user_input_int >= 0); {
        std::shared_ptr<IItem> item = GetItemFromShop::Execute(user_input_int);
        PlayerGetItem::Execute(item);
      }
    }
  }
}
