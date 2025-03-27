#ifndef COMMAND_HANDLER_H
#define COMMAND_HANDLER_H

#include "GameMaster.h"
#include <string>

class CommandHandler {
 private:
  static CommandHandler* instance;
  CommandHandler() = default;

 public:
  static CommandHandler* GetInstance() {
    if (!instance) {
      instance = new CommandHandler();
    }
    return instance;
  }

  void ExecuteCommand(const std::string& command);
};

#endif