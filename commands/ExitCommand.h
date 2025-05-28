#ifndef CommandExit
#define CommandExit

#include "ICommand.h"

class Exit : public ICommand {
 public:
  // Выполняет команду выхода из игры.
  void CommandExecute() override;
};

#endif  // CommandExit
