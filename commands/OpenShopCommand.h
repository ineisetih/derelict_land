#ifndef CommandOpenShop
#define CommandOpenShop

#include "ICommand.h"

class OpenShopCommand : public ICommand {
 public:
  void CommandExecute() override;
};

#endif  // CommandOpenShop
