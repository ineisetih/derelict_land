#ifndef BUY_COMMAND_H
#define BUY_COMMAND_H

#include "ICommand.h"

class BuyCommand : public ICommand {
 public:
  void CommandExecute() override;
};

#endif  // BUY_COMMAND_H