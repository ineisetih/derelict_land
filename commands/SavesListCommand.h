#ifndef SAVE_LIST_COMMAND_H
#define SAVE_LIST_COMMAND_H

#include "ICommand.h"

class ListSavesCommand : public ICommand {
 public:
  void CommandExecute() override;
};

#endif //SAVE_LIST_COMMAND_H