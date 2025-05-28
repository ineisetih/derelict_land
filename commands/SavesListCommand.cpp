#include "SavesListCommand.h"
#include "SaveManager.h"
#include <iostream>
#include <string>

void ListSavesCommand::CommandExecute() {
  auto saves = SaveManager::ListSaves();
  if (saves.empty()) {
    std::cout << "No saves found!\n";
    return;
  }

  std::cout << "Available saves:\n";
  for (const auto& name : saves) {
    std::cout << "- " << name << "\n";
  }
}