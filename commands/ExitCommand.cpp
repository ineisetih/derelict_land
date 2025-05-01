#include "ExitCommand.h"

#include <cstdlib>

void Exit::CommandExecute() {
  std::exit(0);
}
