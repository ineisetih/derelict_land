#ifndef COMMAND_HANDLER_H
#define COMMAND_HANDLER_H

#include <string>

class CommandHandler {
 private:
  static CommandHandler* instance;
  CommandHandler() = default;

 public:
  // Статический метод для получения единственного экземпляра обработчика команд.
  static CommandHandler* GetInstance();
  // Выполняет команду, переданную в виде строки.
  void ExecuteCommand(std::string& command);
};

#endif