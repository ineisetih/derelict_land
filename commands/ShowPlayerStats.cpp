#include "ShowPlayerStats.h"
#include "Player.h"

void ShowPlayerStats::CommandExecute() {
  std::shared_ptr<Player> player = Player::GetInstance(); 
  if (player) {
    std::cout << "Hp: " << player->GetHealth() << std::endl;
    std::cout << "Damage: " << player->GetDamage() << std::endl;
    std::cout << "LVL: " << player->GetLevel() << std::endl;
    std::cout << "Exp: " << player->GetExperience() << std::endl;
  } else {
    std::cout << "No player found" << std::endl;
  }
}
