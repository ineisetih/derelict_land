#ifndef COMMAND_HANDLER_H
#define COMMAND_HANDLER_H

#include <string>

class CommandHandler {
 private:
  static CommandHandler* instance;
  CommandHandler() = default;

 public:
  static CommandHandler* GetInstance();
  void ExecuteCommand(std::string& command);
};

#endif