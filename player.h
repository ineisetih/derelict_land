#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
#include "PlayerInventory.h"

class Player : public Character {
 private:
  float experience;
  int level;
  static Player* instance;

  Player(std::string name, float health, float damage);

 public:
  ~Player() override;

  static Player* CreatePlayer(std::string name = "Hero", float health = 100.0f, float damage = 10.0f);

  // Методы персонажа
  void AddExperience(float exp);
  float GetExperience() const;
  int GetLevel() const;
  void LevelUp();
  void AddLevel(int levels);

  // Работа с инвентарем
  void EquipWeapon(Weapon* weapon);
  void EquipArmor(Armor* armor);
  std::string GetInventoryInfo() const;

  // Сеттеры
  void SetHealth(float health);
  void SetDamage(float damage);
};

#endif  // PLAYER_H