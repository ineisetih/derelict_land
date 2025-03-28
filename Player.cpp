#include "Player.h"
#include <stdexcept>

// ����������� ����������
Player* Player::instance = nullptr;

// �����������
Player::Player(std::string name, float health, float damage)
    : Character(name, health, damage), experience(0), level(1) {
  inventory = new PlayerInventory();
}

// ����������
Player::~Player() {
  delete inventory;
  instance = nullptr;
}

// �������� ������ (��������)
Player* Player::CreatePlayer(std::string name, float health, float damage) {
  if (!instance) {
    instance = new Player(name, health, damage);
  }
  return instance;
}

// ���������� �����
void Player::AddExperience(float exp) {
  if (exp < 0) {
    throw std::invalid_argument("Experience cannot be negative");
  }

  experience += exp;
  std::cout << "Gained " << exp << " experience. Total: " << experience << "/100\n";

  if (experience >= 100) {
    LevelUp();
  }
}

// ��������� ������
void Player::LevelUp() {
  level++;
  damage += 5;
  health += 20;
  experience -= 100;

  std::cout << "Level up! Now you're level " << level << "\n";
  std::cout << "New stats - Health: " << health << ", Damage: " << damage << "\n";
}

// ���������� ������
// void Player::EquipWeapon(Weapon* weapon) {
//   if (!weapon) {
//     throw std::invalid_argument("Cannot equip null weapon");
//   }

//   if (auto* inv = dynamic_cast<PlayerInventory*>(inventory)) {
//     inv->EquipWeapon(weapon);
//     std::cout << "Equipped weapon: " << weapon->GetInfo() << "\n";
//   }
// }

// // ���������� �����
// void Player::EquipArmor(Armor* armor) {
//   if (!armor) {
//     throw std::invalid_argument("Cannot equip null armor");
//   }

//   if (auto* inv = dynamic_cast<PlayerInventory*>(inventory)) {
//     inv->EquipArmor(armor);
//     std::cout << "Equipped armor: " << armor->GetInfo() << "\n";
//   }
// }

// ��������� ���������� �� ���������
std::string Player::GetInventoryInfo() const {
  return inventory ? inventory->GetInfo() : "Inventory not initialized";
}

// �������
float Player::GetExperience() const {
  return experience;
}

int Player::GetLevel() const {
  return level;
}

// �������
void Player::SetHealth(float health) {
  if (health < 0)
    health = 0;
  this->health = health;
}

void Player::SetDamage(float damage) {
  if (damage < 0)
    damage = 0;
  this->damage = damage;
}

// ���������� ������ (��� �������/�����)
void Player::AddLevel(int levels) {
  if (levels <= 0)
    return;

  for (int i = 0; i < levels; ++i) {
    LevelUp();
  }
}