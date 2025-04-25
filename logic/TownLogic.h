#ifndef LogicOfTown
#define LogicOfTown

#include "DefaultLogic.h"

class TownLogic : public DefaultLogic {
 private:
  TownLogic() = default;
  static TownLogic *TownLogicInstance;

 public:
  static TownLogic *GetInstance();
};

#endif  // LogicOfTown
