#ifndef LOAD_GAME_COMMAND_H
#define LOAD_GAME_COMMAND_H

#include "ICommand.h"

class LoadGameCommand : public ICommand {
 public:
  // Выполняет команду загрузки игры.
  void CommandExecute() override;
};
#endif //LOAD_GAME_COMMAND_H