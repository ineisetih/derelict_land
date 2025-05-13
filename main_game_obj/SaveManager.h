#ifndef SAVEMANAGER_H
#define SAVEMANAGER_H

#define SAVE_PATH "saves.txt"

#include "Player.h"
#include <vector>
#include <string>
#include <fstream>

struct PlayerSave {
  std::string name;
  float health;
  float damage;
  float experience;
  int level;
  std::vector<std::string> equippedItems;
  std::vector<std::string> backpackItems;
};

class SaveManager {
 public:
  static void SaveGame(Player* player, const std::string& filename = SAVE_PATH);
  static std::shared_ptr<Player> LoadGame(const std::string& playerName, const std::string& filename = SAVE_PATH);
  static std::vector<std::string> ListSaves(const std::string& filename = SAVE_PATH);
  static bool DeleteSave(const std::string& playerName, const std::string& filename = SAVE_PATH);
  static std::shared_ptr<IItem> ParseItem(const std::string& itemStr);
  static bool IsPlayerExist(const std::string& playerName, const std::string& filename = SAVE_PATH);
};

#endif
