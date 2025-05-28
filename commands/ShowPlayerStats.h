#ifndef CommandShowPlayerStats
#define CommandShowPlayerStats

#include "ICommand.h"

class ShowPlayerStats : public ICommand {
 public:
  // Выполняет команду отображения статистики игрока.
  void CommandExecute() override;
};

#endif  // CommandShowPlayerStats
