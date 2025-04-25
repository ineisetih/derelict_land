#include "PlayerGetItem.h"
#include "Player.h"
#include "GameMaster.h"
#include "PlayerInventory.h"

#include <memory>

void PlayerGetItem::Execute(std::shared_ptr<IItem> item) {
  try{
  Player* player = GameMaster::GetInstance()->GetPlayer();
  if (!player)
    throw std::runtime_error("Player not initialized");

  switch (item->GetType()) {
    case OneHandWeapon:
    std::cout << "case 1\n";
      player->EquipWeapon(item);
      break;
    case BodyArmor:
    std::cout << "case 2\n";
    player->EquipArmor(item);
      break;
    case AttackGem:
      std::cout << "case 3\n";
      player->AddItemToBackpack(item);
      break;
    default:
    std::cout << "case 4\n";
      throw std::runtime_error("Unknown item type");
      break;
  }}
  catch (const std::exception& e) {
    std::cerr << "Item error: " << e.what() << '\n';
  }
}

