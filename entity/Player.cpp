#include "Player.h"
#include "PlayerInventory.h"
#include "SaveManager.h"
#include <stdexcept>

#define DAMAGE_UP_PER_LVL 5
#define HEALTH_UP_PER_LVL 20
#define EXP_DOWN_PER_LVL 100
#define BASE_HP 100.0f
#define BASE_DMG 10.0f

std::shared_ptr<Player> Player::instance = nullptr; 

// Приватный конструктор класса Player.
// Инициализирует игрока с именем, здоровьем, уроном, начальным опытом и уровнем.
Player::Player(std::string name, float health, float damage)
    : Character(name, health, damage), experience(0), level(1) {
  inventory = new PlayerInventory();
}

// Деструктор класса Player.
// Освобождает память, выделенную под инвентарь.
Player::~Player() {
  delete inventory; 
}
// Возвращает единственный экземпляр класса Player (Singleton).
std::shared_ptr<Player> Player::GetInstance(){ 
  if (!instance) {
  }
  return instance;
}

// Создает или возвращает единственный экземпляр класса Player (Singleton).
std::shared_ptr<Player> Player::CreatePlayer(std::string name, float health, float damage) { 
  instance = std::shared_ptr<Player>(new Player(name, health, damage));
  return instance;
}

// Добавляет опыт игроку и проверяет возможность повышения уровня.
void Player::AddExperience(float exp) {
  if (exp < 0) {
    throw std::invalid_argument("Experience cannot be negative");
  }

  experience += exp;
  std::cout << "Gained " << exp << " experience. Total: " << experience << "/100\n";

  while (experience >= 100) {
    LevelUp();
  }
}

// Повышает уровень игрока, увеличивая его характеристики и сбрасывая часть опыта.
void Player::LevelUp() {
  level++;
  damage += DAMAGE_UP_PER_LVL;
  health += HEALTH_UP_PER_LVL;
  experience -= EXP_DOWN_PER_LVL;

  std::cout << "Level up! Now you're level " << level << "\n";
  std::cout << "New stats - Health: " << health << ", Damage: " << damage << "\n";
}

// Экипирует оружие на игрока, если это возможно, и обновляет урон игрока.
void Player::EquipWeapon(std::shared_ptr<IItem> weapon) {
  if (!weapon) {
    throw std::invalid_argument("Cannot equip null weapon");
  }

  if (auto* inv = dynamic_cast<PlayerInventory*>(inventory)) {
    bool is_equipped = inv->EquipWeapon(weapon);
    if (is_equipped) {
      std::cout << "Equipped weapon: " << weapon->GetInfo() << "\n";
    }
    if (weapon) { 
        auto* weaponPtr = dynamic_cast<Weapon*>(weapon.get());
        if (weaponPtr) { 
            this->damage += weaponPtr->GetDamage(); 
        } else {
            std::cerr << "Warning: Attempted to equip an item that is not a Weapon or weapon data is invalid." << std::endl;
        }
    }
  }
}

// Добавляет предмет в рюкзак игрока.
void Player::AddItemToBackpack(std::shared_ptr<IItem> item) {
  inventory->AddItem(item);
}

// Удаляет предмет из рюкзака игрока.
void Player::RemoveItemFromBackpack(std::shared_ptr<IItem> item) {
  inventory->RemoveItem(item);
}

// Экипирует броню на игрока.
void Player::EquipArmor(std::shared_ptr<IItem> armor) {
  if (!armor) {
    throw std::invalid_argument("Cannot equip null armor");
  }

  if (auto* inv = dynamic_cast<PlayerInventory*>(inventory)) {
    inv->EquipArmor(armor);
    std::cout << "Equipped armor: " << armor->GetInfo() << "\n";
  }
}

// Возвращает информацию об инвентаре игрока в виде строки.
std::string Player::GetInventoryInfo() const {
  try {
    std::cout << "Getting inventory info...\n";
    return inventory ? inventory->GetInfo() : "Inventory not initialized";
  } catch (const std::exception& e) {
    std::cerr << "Inventory error: " << e.what() << '\n';
  }
  return "";
}

// Возвращает текущее количество опыта игрока.
float Player::GetExperience() const {
  return experience;
}

// Возвращает текущий уровень игрока.
int Player::GetLevel() const {
  return level;
}

// Устанавливает здоровье игрока, не позволяя ему быть отрицательным.
void Player::SetHealth(float health) {
  if (health < 0)
    health = 0;
  this->health = health;
}

// Устанавливает урон игрока, не позволяя ему быть отрицательным.
void Player::SetDamage(float damage) {
  if (damage < 0)
    damage = 0;
  this->damage = damage;
}

// Устанавливает инвентарь для игрока.
void Player::SetInventory(IInventory* inventory) {
  this->inventory = inventory;
}

// Повышает уровень игрока на указанное количество уровней.
void Player::AddLevel(int levels) {
  if (levels <= 0)
    return;

  for (int i = 0; i < levels; ++i) {
    LevelUp();
  }
}
// Устанавливает количество опыта игрока.
void Player::SetExperience(float xp) {
  experience = xp;
}
// Устанавливает уровень игрока.
void Player::SetLevel(int lvl) {
  level = lvl;
}
