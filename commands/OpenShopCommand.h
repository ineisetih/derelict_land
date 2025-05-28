#ifndef CommandOpenShop
#define CommandOpenShop

#include "ICommand.h"

class OpenShopCommand : public ICommand {
 public:
  // Выполняет команду открытия магазина.
  void CommandExecute() override;
};

#endif  // CommandOpenShop
