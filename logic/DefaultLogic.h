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
  // Конструктор по умолчанию.
  DefaultLogic();
  // Выполняет команду, переданную в виде строки.
  void DoCommand(std::string &console_command);
  // Возвращает карту доступных команд.
  std::unordered_map<std::string, std::shared_ptr<ICommand>> GetCommands();
  // Добавляет команду в список доступных.
  void AddCommand(std::string command_name, std::shared_ptr<ICommand> command);
};

#endif  // LogicDefualt