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
  static std::shared_ptr<Player> instance; 

  // Приватный конструктор для реализации Singleton.
  Player(std::string name, float health = BASE_HP, float damage = BASE_DMG);

 public:
  // Деструктор.
  ~Player() override;

  // Статический метод для создания или получения единственного экземпляра игрока.
  static std::shared_ptr<Player> CreatePlayer(std::string name = "Hero", float health = BASE_HP, float damage = BASE_DMG);
  // Статический метод для получения единственного экземпляра игрока.
  static std::shared_ptr<Player> GetInstance();

  // Добавляет опыт игроку.
  void AddExperience(float exp);
  // Возвращает текущее количество опыта игрока.
  float GetExperience() const;
  // Возвращает текущий уровень игрока.
  int GetLevel() const;
  // Повышает уровень игрока.
  void LevelUp();
  // Добавляет указанное количество уровней игроку.
  void AddLevel(int levels);

  // Экипирует оружие.
  void EquipWeapon(std::shared_ptr<IItem> weapon);
  // Экипирует броню.
  void EquipArmor(std::shared_ptr<IItem> armor);
  // Добавляет предмет в рюкзак.
  void AddItemToBackpack(std::shared_ptr<IItem> item);
  // Удаляет предмет из рюкзака.
  void RemoveItemFromBackpack(std::shared_ptr<IItem> item);
  // Возвращает информацию об инвентаре в виде строки.
  std::string GetInventoryInfo() const;

  // Устанавливает здоровье игрока.
  void SetHealth(float health);
  // Устанавливает урон игрока.
  void SetDamage(float damage);
  // Устанавливает опыт игрока.
  void SetExperience(float xp);
  // Устанавливает уровень игрока.
  void SetLevel(int lvl);
  // Устанавливает инвентарь игрока.
  void SetInventory(IInventory* inventory);
};

#endif  // PLAYER_H