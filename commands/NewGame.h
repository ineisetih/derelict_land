#ifndef CommandNewGame
#define CommandNewGame

#include "ICommand.h"

class NewGame : public ICommand {
 public:
  void CommandExecute() override;
};

#endif  // CommandNewGame
