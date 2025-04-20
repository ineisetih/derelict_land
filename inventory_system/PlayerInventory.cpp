#include "PlayerInventory.h"

#include <algorithm>
#include <string>
#include <iostream>

PlayerInventory::PlayerInventory() : left_hand(nullptr), right_hand(nullptr), body(nullptr) {
}

PlayerInventory::~PlayerInventory() {
  backpack.clear();
}

void PlayerInventory::AddItem(std::shared_ptr<IItem> item) {
  backpack.push_back(item);
}

void PlayerInventory::RemoveItem(std::shared_ptr<IItem> item) {
  auto it = std::find(backpack.begin(), backpack.end(), item);
  if (it != backpack.end()) {
    backpack.erase(it);
  }
}

void PlayerInventory::EquipArmor(std::shared_ptr<IItem> armor) {
  if (!body) {
    body = armor;
  } else {
    std::cout << "Your current armor:\n" << body->GetInfo() << std::endl;
    std::cout << "New Armor:\n" << armor->GetInfo() << std::endl;
    std::string user_input;
    std::cout << "You want to switch? y/n" << std::endl;
    std::cin >> user_input;
    if (user_input == "y") {
      body = armor;
    }
  }
}

void PlayerInventory::EquipWeapon(std::shared_ptr<IItem> weapon) {
  if (!left_hand) {
    left_hand = weapon;
  } else {
    std::cout << "Your current weapon:\n" << left_hand->GetInfo() << std::endl;
    std::cout << "New Weapon:\n" << weapon->GetInfo() << std::endl;
    std::string user_input;
    std::cout << "You want to switch? y/n" << std::endl;
    std::cin >> user_input;
    if (user_input == "y") {
      left_hand = weapon;
    }
  }
}

std::string PlayerInventory::GetInfo() {
  std::string info = "Inventory:\n";
  info += "Left hand: " + (left_hand ? left_hand->GetInfo() : "Empty") + "\n";
  info += "Right hand: " + (right_hand ? right_hand->GetInfo() : "Empty") + "\n";
  info += "Body: " + (body ? body->GetInfo() : "Empty") + "\n";
  info += "Backpack items:\n";

  for (const auto& item : backpack) {
    info += "- " + item->GetInfo() + "\n";
  }

  return info;
}
