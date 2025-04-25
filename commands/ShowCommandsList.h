#ifndef CommandShowCommandsList
#define CommandShowCommandsList

#include "ICommand.h"
#include "DefaultLogic.h"
#include "ShowCommandsList.h"

class ShowCommandsList : public ICommand {
 private:
  DefaultLogic *logic;

 public:
  ShowCommandsList(DefaultLogic *logic);
  void CommandExecute() override;
};

#endif  // CommandShowCommandsList
