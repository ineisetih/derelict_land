#ifndef CommandNewGame
#define CommandNewGame

#include "ICommand.h"

class NewGame : public ICommand {
 public:
  // Выполняет команду начала новой игры.
  void CommandExecute() override;
};

#endif  // CommandNewGame
