#include "SaveManager.h"
#include "GameMaster.h"
#include <sstream>
#include <string>
#include <algorithm>

void SaveManager::SaveGame(Player* player, const std::string& filename) {
  std::ofstream file(filename, std::ios::app);
  if (file.is_open()) {
    file << player->GetName() << "," << player->GetHealth() << "," << player->GetDamage() << ","
         << player->GetExperience() << "," << player->GetLevel() << "\n";
    file.close();
  }
}

PlayerSave SaveManager::LoadGame(const std::string& playerName, const std::string& filename) {
  std::ifstream file(filename);
  std::string line;
  while (getline(file, line)) {
    std::stringstream ss(line);
    std::string name;
    getline(ss, name, ',');

    if (name == playerName) {
      PlayerSave save;
      save.name = name;

      std::string value;
      getline(ss, value, ',');
      save.health = stof(value);

      getline(ss, value, ',');
      save.damage = stof(value);

      getline(ss, value, ',');
      save.experience = stof(value);

      getline(ss, value);
      save.level = stoi(value);

      return save;
    }
  }
  return {"", 0, 0, 0, 0};
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

// bool SaveManager::DeleteSave(const //std::string& playerName, const std::string& //filename) {
//    return true;
// }
