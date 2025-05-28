#ifndef ENEMYFACTORY_H
#define ENEMYFACTORY_H

#include "Enemy.h"
#include <vector>
#include <memory>


class EnemyFactory
{
public:
	// Статический метод для создания врага определенного типа.
	static std::shared_ptr<Enemy> CreateEnemy(EnemyType type);
    // Деструктор.
    ~EnemyFactory() {}
};

#endif // ENEMYFACTORY_H
