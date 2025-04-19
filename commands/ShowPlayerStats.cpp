#include "ShowPlayerStats.h"
#include "GameMaster.h"
#include "Player.h"

void ShowPlayerStats::CommandExecute() {
  if (GameMaster::GetInstance()->GetPlayer() != nullptr) {
    auto player = GameMaster::GetInstance()->GetPlayer();
    std::cout << "Hp: " << player->GetHealth() << std::endl;
    std::cout << "Damage: " << player->GetDamage() << std::endl;
    std::cout << "LVL: " << player->GetLevel() << std::endl;
    std::cout << "Exp: " << player->GetExperience() << std::endl;
  } else {
    std::cout << "No player found" << std::endl;
  }
}
