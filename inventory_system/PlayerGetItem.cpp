#include "PlayerGetItem.h"
#include "Player.h"
#include "GameMaster.h"

#include <memory>

void PlayerGetItem::Execute(std::shared_ptr<IItem> item) {
  Player* player = GameMaster::GetInstance()->GetPlayer();
  if (!player)
    throw std::runtime_error("Player not initialized");

  switch (item->GetType()) {
    case OneHandWeapon:
      player->EquipWeapon(item);
      break;
    case BodyArmor:
      player->EquipArmor(item);
      break;
    case AttackGem:
      break;
    default:
      throw std::runtime_error("Unknown item type");
      break;
  }
}