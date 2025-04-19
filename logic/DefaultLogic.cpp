#include "DefaultLogic.h"
#include "ExitCommand.h"
#include "ShowCommandsList.h"
#include "ShowPlayerStats.h"

DefaultLogic::DefaultLogic() {
  AddCommand("exit", std::make_shared<Exit>());
  AddCommand("help", std::make_shared<ShowCommandsList>(this));
  AddCommand("status", std::make_shared<ShowPlayerStats>());
}

void DefaultLogic::DoCommand(std::string& console_command) {
  if (commands.find(console_command) != commands.end()) {
    commands[console_command]->CommandExecute();
  } else {
    std::cout << "Unknown command!" << std::endl;
  }
}

void DefaultLogic::AddCommand(std::string command_name, std::shared_ptr<ICommand> command) {
  commands[command_name] = command;
}

std::unordered_map<std::string, std::shared_ptr<ICommand>> DefaultLogic::GetCommands() {
  return commands;
}
