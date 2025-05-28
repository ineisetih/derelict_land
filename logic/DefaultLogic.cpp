#include "DefaultLogic.h"
#include "ExitCommand.h"
#include "ShowCommandsList.h"
#include "ShowPlayerStats.h"

// Конструктор класса DefaultLogic.
// Добавляет базовые команды, доступные в любом состоянии игры.
DefaultLogic::DefaultLogic() {
  AddCommand("exit", std::make_shared<Exit>());
  AddCommand("help", std::make_shared<ShowCommandsList>(this));
  AddCommand("status", std::make_shared<ShowPlayerStats>());
}

// Выполняет команду, введенную пользователем.
void DefaultLogic::DoCommand(std::string& console_command) {
  if (commands.find(console_command) != commands.end()) {
    commands[console_command]->CommandExecute();
  } else {
    std::cout << ">" << std::endl;
  }
}

// Добавляет новую команду в список доступных команд.
void DefaultLogic::AddCommand(std::string command_name, std::shared_ptr<ICommand> command) {
  commands[command_name] = command;
}

// Возвращает карту доступных команд.
std::unordered_map<std::string, std::shared_ptr<ICommand>> DefaultLogic::GetCommands() {
  return commands;
}
