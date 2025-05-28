#ifndef LogicOfTown
#define LogicOfTown

#include "DefaultLogic.h"

class TownLogic : public DefaultLogic {
 private:
  TownLogic() = default;
  static TownLogic *TownLogicInstance;

 public:
  // Статический метод для получения единственного экземпляра логики города.
  static TownLogic *GetInstance();
};

#endif  // LogicOfTown
