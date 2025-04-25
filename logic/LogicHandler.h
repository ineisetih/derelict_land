#ifndef HandlerLogic
#define HandlerLogic

#include "DefaultLogic.h"

class LogicHandler {
 private:
  LogicHandler() = default;

 public:
  static LogicHandler *LogicHandlerInstance;
  static LogicHandler *GetInstance();
  void ChangeLogic(DefaultLogic *new_logic);
};

#endif  // HandlerLogic
