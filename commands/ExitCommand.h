#ifndef CommandExit
#define CommandExit

#include "ICommand.h"

class Exit : public ICommand {
 public:
  void CommandExecute() override;
};

#endif  // CommandExit
