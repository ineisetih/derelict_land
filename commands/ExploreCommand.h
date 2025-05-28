#ifndef CommandExplore
#define CommandExplore

#include "ICommand.h"

class ExploreCommand : public ICommand {
 public:
  // Выполняет команду исследования.
  void CommandExecute() override;
};

#endif  // ExploreCommand
