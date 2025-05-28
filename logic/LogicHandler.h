#ifndef HandlerLogic
#define HandlerLogic

#include "DefaultLogic.h"

class LogicHandler {
 private:
  DefaultLogic* current_logic = nullptr; // Added to store current logic
  LogicHandler() = default;

 public:
  static LogicHandler *LogicHandlerInstance;
  static LogicHandler *GetInstance();
  void ChangeLogic(DefaultLogic *new_logic);
  DefaultLogic* GetCurrentLogic() const; // Added
};

#endif  // HandlerLogic
