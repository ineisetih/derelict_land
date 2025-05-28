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
  // Статический метод для получения единственного экземпляра логики боя.
  static FightLogic* GetInstance();
  // Добавляет врага в список активных врагов.
  void AddEnemy(std::shared_ptr<Enemy> enemy);
  // Удаляет врага из списка активных врагов.
  void RemoveEnemy(std::shared_ptr<Enemy> enemy);
  // Создает врагов для текущего боя.
  void CreateEnemies();
  // Возвращает список активных врагов.
  std::vector<std::shared_ptr<Enemy>> GetEnemies();

 public:
  // Начинает бой.
  void StartFight();
  // Очищает список врагов (не реализовано в .cpp).
  void ClearEnemies();
};

#endif  // LogicOfFight
