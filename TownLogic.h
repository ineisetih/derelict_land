#ifndef TOWN_LOGIC_H
#define TOWN_LOGIC_H

#include "UIlogic.cpp"

class TownLogic : public DefaultLogic {
private:
  TownLogic() = default;
  static TownLogic* TownLogicInstance;

public:
  static TownLogic* GetInstance();

};

#endif  // TOWN_LOGIC_H