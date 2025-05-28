#include "ShowCommandsList.h"
#include "DefaultLogic.h"
#include "ICommand.h"

// Конструктор команды ShowCommandsList.
// Принимает указатель на объект DefaultLogic для доступа к списку команд.
ShowCommandsList::ShowCommandsList(DefaultLogic *logic) : logic(logic) {
}
// Выполняет команду отображения списка доступных команд.
void ShowCommandsList::CommandExecute() {
  std::cout << "Available commands:" << std::endl;
  for (const auto &pair : logic->GetCommands()) {
    std::cout << "- " << pair.first << std::endl;
  }
}
