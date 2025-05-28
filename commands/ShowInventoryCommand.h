#ifndef CommandShowInventory
#define CommandShowInventory

#include "ICommand.h"

class ShowInventoryCommand : public ICommand {
 public:
  // Выполняет команду отображения инвентаря игрока.
  void CommandExecute() override;
};

#endif  // CommandShowInventory
