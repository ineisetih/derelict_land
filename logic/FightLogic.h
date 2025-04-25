#ifndef LogicOfFight
#define LogicOfFight

#include "DefaultLogic.h"
#include <vector>
#include "Enemy.h"

class FightLogic : public DefaultLogic {
 private:
  FightLogic() = default;
  static FightLogic* MainFightLogicInstance;
  std::vector<std::shared_ptr<Enemy>> enemies;

 public:
  static FightLogic* GetInstance();
  void AddEnemy(std::shared_ptr<Enemy> enemy);
  void RemoveEnemy(std::shared_ptr<Enemy> enemy);
  void CreateEnemies();
  std::vector<std::shared_ptr<Enemy>> GetEnemies();

 public:
  void StartFight();
  void ClearEnemies();
};

#endif  // LogicOfFight
