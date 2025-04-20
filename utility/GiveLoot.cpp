#include "GiveLoot.h"
#include "PlayerGetItem.h"

#include <iostream>
#include <string>

void GiveLoot::Execute(std::vector<std::shared_ptr<IItem>> loot) {
    int i = 1;
    for (auto item : loot) {
       std::cout << i++ << ". " << item->GetInfo() << std::endl;
    }
    std::cout << "To take reward type numbers of items";
    std::string user_input;
    for (auto a : user_input){
        if (a != ' '){
            PlayerGetItem::Execute(loot[static_cast<int>(a) - 1]);
        }
    }
}
