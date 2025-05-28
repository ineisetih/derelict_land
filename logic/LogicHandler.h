#ifndef HandlerLogic
#define HandlerLogic

#include "DefaultLogic.h"

class LogicHandler {
 private:
  DefaultLogic* current_logic = nullptr; // Added to store current logic
  LogicHandler() = default;

 public:
  static LogicHandler *LogicHandlerInstance;
  // Статический метод для получения единственного экземпляра обработчика логики.
  static LogicHandler *GetInstance();
  // Изменяет текущую логику игры.
  void ChangeLogic(DefaultLogic *new_logic);
  // Возвращает текущую активную логику игры.
  DefaultLogic* GetCurrentLogic() const; // Added
};

#endif  // HandlerLogic
