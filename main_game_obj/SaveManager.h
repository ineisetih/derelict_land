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
  // Сохраняет текущее состояние игры для указанного игрока.
  static void SaveGame(std::shared_ptr<Player> player);
  // Загружает сохраненное состояние игры для игрока с указанным именем.
  // filename - имя файла сохранения (в текущей реализации используется фиксированный путь к БД).
  static std::shared_ptr<Player> LoadGame(const std::string& playerName, const std::string& filename = SAVE_PATH);
  // Возвращает список имен всех доступных сохранений.
  // filename - имя файла сохранения (в текущей реализации используется фиксированный путь к БД).
  static std::vector<std::string> ListSaves(const std::string& filename = SAVE_PATH);
  // Удаляет сохранение для игрока с указанным именем (не реализовано в .cpp).
  static bool DeleteSave(const std::string& playerName, const std::string& filename = SAVE_PATH);
  // Преобразует строковое представление предмета в объект IItem.
  static std::shared_ptr<IItem> ParseItem(const std::string& itemStr);
  // Проверяет, существует ли сохранение для игрока с указанным именем (не реализовано в .cpp).
  static bool IsPlayerExist(const std::string& playerName, const std::string& filename = SAVE_PATH);
};

#endif
