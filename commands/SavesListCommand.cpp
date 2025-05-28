#include "SavesListCommand.h"
#include "SaveManager.h"
#include <iostream>
#include <string>

// Выполняет команду отображения списка сохранений.
// Получает список имен сохраненных игр и выводит их в консоль.
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