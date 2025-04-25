#ifndef LogicDefualt
#define LogicDefualt

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <memory>
#include "ICommand.h"

class DefaultLogic {
 protected:
  std::unordered_map<std::string, std::shared_ptr<ICommand>> commands;

 public:
  DefaultLogic();
  void DoCommand(std::string &console_command);
  std::unordered_map<std::string, std::shared_ptr<ICommand>> GetCommands();
  void AddCommand(std::string command_name, std::shared_ptr<ICommand> command);
};

#endif  // LogicDefualt