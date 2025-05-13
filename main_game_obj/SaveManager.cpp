#include "SaveManager.h"
#include "GameMaster.h"
#include "PlayerInventory.h"
#include "PlayerGetItem.h"
#include <sstream>
#include <string>
#include <algorithm>
#include "Armor.h"
#include "Chestplate.h"
#include "Gems.h"
#include "Sword.h"

#define DEFAULT_SWORD_SAVE_NUMBER 8
#define DEFAULT_CHESTPLATE_SAVE_NUMBER 9
#define DEFAULT_GEM_SAVE_NUMBER 10

bool SaveManager::IsPlayerExist(const std::string& playerName, const std::string& filename) {
  std::ifstream file(filename);
  std::string line;
  while (getline(file, line)) {
    std::stringstream ss(line);
    std::string token;
    std::vector<std::string> tokens;

    while (getline(ss, token, ',')) {
      tokens.push_back(token);
    }
    if (tokens.empty() || tokens[0] != playerName) {
      continue;
    }
    return true;
  }
  return false;
}

void SaveManager::SaveGame(Player* player, const std::string& filename) {
  if (IsPlayerExist(player->GetName())) {
    DeleteSave(player->GetName());
  }
  std::ofstream file(filename, std::ios::app);
  if (file.is_open()) {

    file << player->GetName() << "," << player->GetHealth() << "," << player->GetDamage() << ","
         << player->GetExperience() << "," << player->GetLevel() << ",";

    auto inventory = dynamic_cast<PlayerInventory*>(player->GetInventory());
    if (inventory) {
      file << (inventory->GetLeftHand() ? inventory->GetLeftHand()->GetInfo() : "Empty") << ",";
      file << (inventory->GetRightHand() ? inventory->GetRightHand()->GetInfo() : "Empty") << ",";
      file << (inventory->GetBody() ? inventory->GetBody()->GetInfo() : "Empty") << ",";

      for (auto item : inventory->GetBackpack()) {
        file << item->GetInfo() << ",";
      }
    }
    file << "\n";
    file.close();
  }
}

std::shared_ptr<Player> SaveManager::LoadGame(const std::string& playerName, const std::string& filename) {
  std::ifstream file(filename);
  std::string line;
  try {
    while (getline(file, line)) {
      std::stringstream ss(line);
      std::string token;
      std::vector<std::string> tokens;

      while (getline(ss, token, ',')) {
        tokens.push_back(token);
      }

      if (tokens.empty() || tokens[0] != playerName) {
        continue;
      }

      if (tokens.size() < 5) {
        continue;
      }

      // Создаём игрока
      auto player = std::shared_ptr<Player>(Player::CreatePlayer(tokens[0]));  // имя
      GameMaster::GetInstance()->SetPlayer(player.get());
      player->SetHealth(std::stof(tokens[1]));
      player->SetDamage(std::stof(tokens[2]));
      player->SetExperience(std::stof(tokens[3]));
      player->SetLevel(std::stoi(tokens[4]));

      auto inventory = std::make_shared<PlayerInventory>();
      GameMaster::GetInstance()->GetPlayer()->SetInventory(inventory.get());
      if (inventory) {
        // Экипировка (тут костылик, надо доработать)
        if (tokens.size() > 5 && tokens[5] != "Empty") {
          auto item = ParseItem(tokens[5]);
          if (item) {
            PlayerGetItem::Execute(item);
          }
        }
        if (tokens.size() > 6 && tokens[6] != "Empty") {
          auto item = ParseItem(tokens[6]);
          if (item) {
            PlayerGetItem::Execute(item);
          }
        }
        if (tokens.size() > 7 && tokens[7] != "Empty") {
          auto item = ParseItem(tokens[7]);
          if (item) {
            PlayerGetItem::Execute(item);
          }
        }

        // Рюкзак
        for (size_t i = 8; i < tokens.size(); ++i) {
          if (!tokens[i].empty()) {
            auto item = ParseItem(tokens[i]);
            if (item) {
              PlayerGetItem::Execute(item);
            }
          }
        }
      }
      return player;
    }
  } catch (const std::exception& e) {
    std::cerr << "Error loading game: " << e.what() << std::endl;
  }

  return nullptr;
}
std::vector<std::string> SaveManager::ListSaves(const std::string& filename) {
  std::vector<std::string> saves;
  std::ifstream file(filename);
  std::string line;

  while (getline(file, line)) {
    size_t pos = line.find(',');
    if (pos != std::string::npos) {
      saves.push_back(line.substr(0, pos));
    }
  }

  return saves;
}

bool SaveManager::DeleteSave(const std::string& playerName, const std::string& filename) {
  std::ifstream inputFile(filename);

  std::ofstream tempFile("temp_saves.txt");
  if (!tempFile.is_open()) {
    std::cerr << "Error opening temporary file for writing." << std::endl;
    return false;
  }

  std::string line;
  bool found = false;
  while (getline(inputFile, line)) {
    if (line.find(playerName + ",") != 0) {
      tempFile << line << std::endl;
    } else {
      found = true;
    }
  }

  inputFile.close();
  tempFile.close();
  return std::rename("temp_saves.txt", filename.c_str()) == 0 && found;
}

std::shared_ptr<IItem> SaveManager::ParseItem(const std::string& itemStr) {
  try {
    if (itemStr.find("Sword") != std::string::npos) {
      size_t dmgStart = itemStr.find("Damage: ");
      if (dmgStart == std::string::npos)
        return nullptr;

      dmgStart += DEFAULT_SWORD_SAVE_NUMBER;  // Длина "Damage: "
      size_t dmgEnd = itemStr.find_first_of(",)", dmgStart);
      float damage = stof(itemStr.substr(dmgStart, dmgEnd - dmgStart));
      return std::make_shared<Sword>("Sword", damage);
    } else if (itemStr.find("Chestplate") != std::string::npos) {
      size_t defStart = itemStr.find("Defence: ");
      if (defStart == std::string::npos)
        return nullptr;

      defStart += DEFAULT_CHESTPLATE_SAVE_NUMBER;  // Длина "Defence: "
      size_t defEnd = itemStr.find_first_of(",)", defStart);
      float defence = stof(itemStr.substr(defStart, defEnd - defStart));
      return std::make_shared<Chestplate>("Chestplate", defence, 1);
    } else if (itemStr.find("Gem") != std::string::npos) {
      size_t defStart = itemStr.find("bonus: ");
      if (defStart == std::string::npos)
        return nullptr;

      defStart += DEFAULT_CHESTPLATE_SAVE_NUMBER;
      size_t defEnd = itemStr.find_first_of(",)", defStart);
      float bonus = stof(itemStr.substr(defStart, defEnd - defStart));
      return std::make_shared<Gem>("Gem", ItemType::AttackGem, bonus);
    }
  } catch (const std::exception& e) {
    std::cerr << "Error parsing item: " << e.what() << std::endl;
  }
  return nullptr;
}