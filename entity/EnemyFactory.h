#ifndef ENEMYFACTORY_H
#define ENEMYFACTORY_H

#include "Enemy.h"
#include <vector>
#include <memory>


class EnemyFactory
{
public:
	virtual std::shared_ptr<Enemy> CreateEnemy(EnemyType type);
    virtual ~EnemyFactory() {}
};

#endif // ENEMYFACTORY_H


