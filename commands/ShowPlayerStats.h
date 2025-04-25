#ifndef CommandShowPlayerStats
#define CommandShowPlayerStats

#include "ICommand.h"

class ShowPlayerStats : public ICommand {
 public:
  void CommandExecute() override;
};

#endif  // CommandShowPlayerStats
