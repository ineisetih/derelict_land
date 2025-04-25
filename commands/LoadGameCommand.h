#ifndef LOAD_GAME_COMMAND_H
#define LOAD_GAME_COMMAND_H

#include "ICommand.h"

class LoadGameCommand : public ICommand {
 public:
  void CommandExecute() override;
};
#endif //LOAD_GAME_COMMAND_H