#include "SaveManager.h"
#include "PlayerInventory.h"
#include "PlayerGetItem.h"
#include "sqlite3.h"
#include "json.hpp"
#include <sstream>
#include <fstream>
#include <iostream>
#include "Armor.h"
#include "Chestplate.h"
#include "Gems.h"
#include "Sword.h"

#define DEFAULT_SWORD_SAVE_NUMBER 8
#define DEFAULT_CHESTPLATE_SAVE_NUMBER 9
#define DEFAULT_GEM_SAVE_NUMBER 10

using json = nlohmann::json;
const char* DB_PATH = "player_progress.db";

// Сохраняет состояние игры для указанного игрока в базу данных SQLite.
// Создает таблицу player_progress, если она не существует, и записывает или обновляет данные игрока.
void SaveManager::SaveGame(std::shared_ptr<Player> player) {
  sqlite3* db;
  char* errMsg = nullptr;

  if (sqlite3_open(DB_PATH, &db) != SQLITE_OK) {
    std::cerr << "[SQLite] Failed to open DB: " << sqlite3_errmsg(db) << std::endl;
    return;
  }

  const char* createTableSQL =
      "CREATE TABLE IF NOT EXISTS player_progress ("
      "nickname TEXT PRIMARY KEY,"
      "hp REAL,"
      "damage REAL,"
      "exp REAL,"
      "level INTEGER,"
      "left_hand TEXT,"
      "right_hand TEXT,"
      "body TEXT,"
      "inventory TEXT);";

  if (sqlite3_exec(db, createTableSQL, nullptr, nullptr, &errMsg) != SQLITE_OK) {
    std::cerr << "[SQLite] Failed to create table: " << errMsg << std::endl;
    sqlite3_free(errMsg);
    sqlite3_close(db);
    return;
  }

  auto inventory = dynamic_cast<PlayerInventory*>(player->GetInventory());
  std::string left = inventory && inventory->GetLeftHand() ? inventory->GetLeftHand()->GetInfo() : "Empty";
  std::string right = inventory && inventory->GetRightHand() ? inventory->GetRightHand()->GetInfo() : "Empty";
  std::string body = inventory && inventory->GetBody() ? inventory->GetBody()->GetInfo() : "Empty";

  std::vector<std::string> backpack;
  if (inventory) {
    for (auto item : inventory->GetBackpack()) {
      backpack.push_back(item->GetInfo());
    }
  }
  json invJson = backpack;

  const char* insertSQL =
      "REPLACE INTO player_progress (nickname, hp, damage, exp, level, left_hand, right_hand, body, inventory) "
      "VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?);";

  sqlite3_stmt* stmt;
  if (sqlite3_prepare_v2(db, insertSQL, -1, &stmt, nullptr) != SQLITE_OK) {
    std::cerr << "[SQLite] Failed to prepare insert: " << sqlite3_errmsg(db) << std::endl;
    sqlite3_close(db);
    return;
  }

  sqlite3_bind_text(stmt, 1, player->GetName().c_str(), -1, SQLITE_TRANSIENT);
  sqlite3_bind_double(stmt, 2, player->GetHealth());
  sqlite3_bind_double(stmt, 3, player->GetDamage());
  sqlite3_bind_double(stmt, 4, player->GetExperience());
  sqlite3_bind_int(stmt, 5, player->GetLevel());
  sqlite3_bind_text(stmt, 6, left.c_str(), -1, SQLITE_TRANSIENT);
  sqlite3_bind_text(stmt, 7, right.c_str(), -1, SQLITE_TRANSIENT);
  sqlite3_bind_text(stmt, 8, body.c_str(), -1, SQLITE_TRANSIENT);
  sqlite3_bind_text(stmt, 9, invJson.dump().c_str(), -1, SQLITE_TRANSIENT);

  if (sqlite3_step(stmt) != SQLITE_DONE) {
    std::cerr << "[SQLite] Failed to insert: " << sqlite3_errmsg(db) << std::endl;
  }

  sqlite3_finalize(stmt);
  sqlite3_close(db);
}

// Загружает состояние игры для игрока с указанным именем из базы данных SQLite.
// Возвращает умный указатель на объект Player в случае успеха, иначе nullptr.
std::shared_ptr<Player> SaveManager::LoadGame(const std::string& playerName, const std::string& filename) {
  sqlite3* db;
  if (sqlite3_open(DB_PATH, &db) != SQLITE_OK) {
    std::cerr << "[SQLite] Failed to open DB: " << sqlite3_errmsg(db) << std::endl;
    return nullptr;
  }

  const char* query =
      "SELECT hp, damage, exp, level, left_hand, right_hand, body, inventory FROM player_progress WHERE nickname = ?;";
  sqlite3_stmt* stmt;
  if (sqlite3_prepare_v2(db, query, -1, &stmt, nullptr) != SQLITE_OK) {
    std::cerr << "[SQLite] Prepare failed: " << sqlite3_errmsg(db) << std::endl;
    sqlite3_close(db);
    return nullptr;
  }

  sqlite3_bind_text(stmt, 1, playerName.c_str(), -1, SQLITE_TRANSIENT);

  std::shared_ptr<Player> player = nullptr;
  if (sqlite3_step(stmt) == SQLITE_ROW) {
    float hp = static_cast<float>(sqlite3_column_double(stmt, 0));
    float dmg = static_cast<float>(sqlite3_column_double(stmt, 1));
    float exp = static_cast<float>(sqlite3_column_double(stmt, 2));
    int level = sqlite3_column_int(stmt, 3);

    const char* left = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4));
    const char* right = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5));
    const char* body = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 6));
    const char* invStr = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 7));

    player = Player::CreatePlayer(playerName, hp, dmg); 
    player->SetExperience(exp);
    player->SetLevel(level);

    PlayerInventory* actual_player_inventory = dynamic_cast<PlayerInventory*>(player->GetInventory());
    if (!actual_player_inventory) {
        std::cerr << "[LoadGame] Critical error: Player object does not have a valid PlayerInventory." << std::endl;
    }

    if (left && std::string(left) != "Empty")
      PlayerGetItem::Execute(ParseItem(left));
    if (right && std::string(right) != "Empty")
      PlayerGetItem::Execute(ParseItem(right)); 
    if (body && std::string(body) != "Empty")
      PlayerGetItem::Execute(ParseItem(body));

    std::vector<std::string> backpack_item_strings;
    if (invStr) { 
        try {
            backpack_item_strings = json::parse(invStr);
        } catch (const json::parse_error& e) {
            std::cerr << "[SQLite] Failed to parse inventory JSON: " << e.what() << ". JSON: " << invStr << std::endl;
        }
    }
    for (const auto& itemStr : backpack_item_strings) {
      if (!itemStr.empty()) {
        auto parsed_item = ParseItem(itemStr);
        if (parsed_item) PlayerGetItem::Execute(parsed_item);
      }
    }
  }

  sqlite3_finalize(stmt);
  sqlite3_close(db);
  return player;
}

// Возвращает вектор строк с именами всех сохраненных игроков из базы данных SQLite.
// Параметр filename в данной реализации не используется, так как путь к БД фиксирован (DB_PATH).
std::vector<std::string> SaveManager::ListSaves(const std::string& filename) {
  std::vector<std::string> saves;
  sqlite3* db;

  if (sqlite3_open(DB_PATH, &db) != SQLITE_OK) {
    std::cerr << "[SQLite] Failed to open DB: " << sqlite3_errmsg(db) << std::endl;
    return saves;
  }

  const char* sql = "SELECT nickname FROM player_progress;";
  sqlite3_stmt* stmt;

  if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) {
    std::cerr << "[SQLite] Prepare failed: " << sqlite3_errmsg(db) << std::endl;
    sqlite3_close(db);
    return saves;
  }

  while (sqlite3_step(stmt) == SQLITE_ROW) {
    const char* name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
    if (name) {
      saves.emplace_back(name);
    }
  }

  sqlite3_finalize(stmt);
  sqlite3_close(db);
  return saves;
}

// Разбирает строку, представляющую предмет, и создает соответствующий объект IItem.
// Поддерживает разбор "Sword", "Chestplate" и "Gem".
std::shared_ptr<IItem> SaveManager::ParseItem(const std::string& itemStr) {
  try {
    if (itemStr.find("Sword") != std::string::npos) {
      size_t dmgStart = itemStr.find("Damage: ");
      if (dmgStart == std::string::npos)
        return nullptr;
      dmgStart += DEFAULT_SWORD_SAVE_NUMBER;
      size_t dmgEnd = itemStr.find_first_of(",)", dmgStart);
      float damage = stof(itemStr.substr(dmgStart, dmgEnd - dmgStart));
      return std::make_shared<Sword>("Sword", damage);

    } else if (itemStr.find("Chestplate") != std::string::npos) {
      size_t defStart = itemStr.find("Defence: ");
      if (defStart == std::string::npos)
        return nullptr;
      defStart += DEFAULT_CHESTPLATE_SAVE_NUMBER;
      size_t defEnd = itemStr.find_first_of(",)", defStart);
      float defence = stof(itemStr.substr(defStart, defEnd - defStart));
      return std::make_shared<Chestplate>("Chestplate", defence, 1);

    } else if (itemStr.find("Gem") != std::string::npos) {
      size_t defStart = itemStr.find("bonus: ");
      if (defStart == std::string::npos)
        return nullptr;
      defStart += DEFAULT_GEM_SAVE_NUMBER;
      size_t defEnd = itemStr.find_first_of(",)", defStart);
      float bonus = stof(itemStr.substr(defStart, defEnd - defStart));
      return std::make_shared<Gem>("Gem", ItemType::AttackGem, bonus);
    }
  } catch (const std::exception& e) {
    std::cerr << "[ParseItem] Error: " << e.what() << std::endl;
  }
  return nullptr;
}
