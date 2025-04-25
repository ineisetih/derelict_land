#ifndef CommandExplore
#define CommandExplore

#include "ICommand.h"

class ExploreCommand : public ICommand {
 public:
  void CommandExecute() override;
};

#endif  // ExploreCommand
