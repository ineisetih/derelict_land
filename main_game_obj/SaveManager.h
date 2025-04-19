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
};

class SaveManager {
 public:
  static void SaveGame(Player* player, const std::string& filename = SAVE_PATH);
  static PlayerSave LoadGame(const std::string& playerName, const std::string& filename = SAVE_PATH);
  static std::vector<std::string> ListSaves(const std::string& filename = SAVE_PATH);
 // static bool DeleteSave(const std::string& playerName, const std::string& filename = "saves.txt");
};

#endif
