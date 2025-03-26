#include "Inventory.h"

PlayerInventory::PlayerInventory() : left_hand(nullptr), right_hand(nullptr), body(nullptr) {
}

PlayerInventory::~PlayerInventory() {
  for (auto item : backpack) {
    delete item;
  }
}

void PlayerInventory::AddItem(IItem* item) {
  backpack.push_back(item);
}

void PlayerInventory::RemoveItem(IItem* item) {
  auto it = std::find(backpack.begin(), backpack.end(), item);
  if (it != backpack.end()) {
    backpack.erase(it);
    delete item;
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