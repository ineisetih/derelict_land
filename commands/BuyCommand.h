#ifndef BUY_COMMAND_H
#define BUY_COMMAND_H

#include "ICommand.h"

class BuyCommand : public ICommand {
 public:
  // Выполняет команду покупки.
  void CommandExecute() override;
};

#endif  // BUY_COMMAND_H