#ifndef CommandShowCommandsList
#define CommandShowCommandsList

#include "ICommand.h"
#include "DefaultLogic.h"
#include "ShowCommandsList.h"

class ShowCommandsList : public ICommand {
 private:
  DefaultLogic *logic;

 public:
  // Конструктор, принимающий указатель на объект DefaultLogic.
  ShowCommandsList(DefaultLogic *logic);
  // Выполняет команду отображения списка доступных команд.
  void CommandExecute() override;
};

#endif  // CommandShowCommandsList
