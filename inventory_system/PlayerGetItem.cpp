#include "PlayerGetItem.h"
#include "Player.h"
#include "PlayerInventory.h"

#include <memory>

void PlayerGetItem::Execute(std::shared_ptr<IItem> item) {
  try {
    std::shared_ptr<Player> player = Player::GetInstance();
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
        player->AddItemToBackpack(item);
        break;
      default:
        throw std::runtime_error("Unknown item type");
        break;
    }
  } catch (const std::exception& e) {
    std::cerr << "Item error: " << e.what() << '\n';
  }
}
