#ifndef ITEMS
#define ITEMS

#include <string>

class IItem {
    public:
    virtual void GetInfo() = 0;
    virtual ~IItem() = default;
};

class Weapon : public IItem {
    protected:
    std::string name;
    float damage;
    public:
    void GetInfo() override;
};


class Sword : public Weapon {
    public:
    Sword(std::string name, float damage);
    Sword();
};

#endif 