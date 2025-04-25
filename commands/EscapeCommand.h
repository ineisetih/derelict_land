#ifndef ESCAPE_COMMAND_H
#define ESCAPE_COMMAND_H

#include "ICommand.h"

class EscapeCommand : public ICommand {
 public:
  void CommandExecute() override;
};

#endif  // ESCAPE_COMMAND_H