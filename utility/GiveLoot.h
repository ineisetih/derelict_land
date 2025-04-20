#ifndef GIVE_LOOT_H
#define GIVE_LOOT_H

#include "ItemInteface.h"

#include <vector>
#include <memory>


class GiveLoot{
private:
    public:
    static void Execute(std::vector<std::shared_ptr<IItem>> loot);

};

#endif //GIVE_LOOT_H