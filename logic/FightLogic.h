#ifndef LogicOfFight
#define LogicOfFight

#include "DefaultLogic.h"
#include <vector>
#include "Enemy.h"

class FightLogic : public DefaultLogic {
 private:
  FightLogic() = default;
  static FightLogic* MainFightLogicInstance;
  std::vector<Enemy*> enemies;

 public:
  static FightLogic* GetInstance();
  void AddEnemy(Enemy* enemy);
  void RemoveEnemy(Enemy* enemy);
  std::vector<Enemy*> GetEnemies();

 public:
  void StartFight();
  void ClearEnemies();
};

#endif  // LogicOfFight
