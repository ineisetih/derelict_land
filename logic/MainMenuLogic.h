#ifndef LogicOfMainMenu
#define LogicOfMainMenu

#include "DefaultLogic.h"

class MainMenuLogic : public DefaultLogic {
 private:
  MainMenuLogic() = default;
  static MainMenuLogic *MainMenuLogicInstance;

 public:
  // Статический метод для получения единственного экземпляра логики главного меню.
  static MainMenuLogic *GetInstance();
};

#endif  // LogicOfMainMenu
