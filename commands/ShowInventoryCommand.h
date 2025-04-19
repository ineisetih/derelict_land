#ifndef CommandShowInventory
#define CommandShowInventory

#include "ICommand.h"

class ShowInventoryCommand : public ICommand {
 public:
  void CommandExecute() override;
};

#endif  // CommandShowInventory
