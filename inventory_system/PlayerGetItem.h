#ifndef PLAYER_GET_ITEM_H
#define PLAYER_GET_ITEM_H

#include "Player.h"
#include "Weapon.h"
#include <memory>

class PlayerGetItem {
 public:
  static void Execute(std::shared_ptr<IItem> item);
};



#endif  // PLAYER_GET_ITEM_H