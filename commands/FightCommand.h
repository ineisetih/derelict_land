#ifndef FIGHT_COMMAND_H
#define FIGHT_COMMAND_H

#include "ICommand.h"

class FightCommand : public ICommand {
 public:
  void CommandExecute() override;
};

#endif  // FIGHT_COMMAND_H