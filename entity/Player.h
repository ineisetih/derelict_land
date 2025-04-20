#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
#include "Armor.h"
#include "Weapon.h"

#define BASE_HP 100.0f
#define BASE_DMG 10.0f


class Player : public Character {
 private:
  float experience;
  int level;
  static Player* instance;

  Player(std::string name, float health, float damage);

 public:
  ~Player() override;

  static Player* CreatePlayer(std::string name = "Hero", float health = BASE_HP, float damage = BASE_DMG);

  void AddExperience(float exp);
  float GetExperience() const;
  int GetLevel() const;
  void LevelUp();
  void AddLevel(int levels);

  void EquipWeapon(std::shared_ptr<IItem> weapon);
  void EquipArmor(std::shared_ptr<IItem> armor);
  std::string GetInventoryInfo() const;

  void SetHealth(float health);
  void SetDamage(float damage);
};

#endif  // PLAYER_H