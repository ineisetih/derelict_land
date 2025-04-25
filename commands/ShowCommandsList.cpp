#include "ShowCommandsList.h"
#include "DefaultLogic.h"
#include "ICommand.h"

ShowCommandsList::ShowCommandsList(DefaultLogic *logic) : logic(logic) {
}
void ShowCommandsList::CommandExecute() {
  std::cout << "Available commands:" << std::endl;
  for (const auto &pair : logic->GetCommands()) {
    std::cout << "- " << pair.first << std::endl;
  }
}
