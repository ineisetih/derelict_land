#ifndef LogicOfMainMenu
#define LogicOfMainMenu

#include "DefaultLogic.h"

class MainMenuLogic : public DefaultLogic {
 private:
  MainMenuLogic() = default;
  static MainMenuLogic *MainMenuLogicInstance;

 public:
  static MainMenuLogic *GetInstance();
};

#endif  // LogicOfMainMenu
