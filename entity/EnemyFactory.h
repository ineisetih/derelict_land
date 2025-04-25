#ifndef ENEMYFACTORY_H
#define ENEMYFACTORY_H

#include "Enemy.h"
#include <vector>
#include <memory>


class EnemyFactory
{
public:
	static std::shared_ptr<Enemy> CreateEnemy(EnemyType type);
    ~EnemyFactory() {}
};

#endif // ENEMYFACTORY_H


