#ifndef SAVE_LIST_COMMAND_H
#define SAVE_LIST_COMMAND_H

#include "ICommand.h"

class ListSavesCommand : public ICommand {
 public:
  // Выполняет команду отображения списка сохранений.
  void CommandExecute() override;
};

#endif //SAVE_LIST_COMMAND_H