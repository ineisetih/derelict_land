#include <iostream>
#include <string>

class IItem{
    public:
    std::string name;
    virtual void PrintInfo() = 0;
};

class IWeapon : public IItem{
    private:
    float damage;
    public:
    
    void PrintInfo() override;
    void attack();
};

class IArmor : public IItem{
    private:
    float defence;
    public:
    void PrintInfo() override;
};

class Sword : public IWeapon{
    public:
    void PrintInfo() override;
};

class Bow : public IWeapon{
    public:
    void PrintInfo() override;
};


class Shield : public IArmor{
    public:
    void PrintInfo() override;
};

class IFactory{
    public:
    virtual IItem* createItem() = 0;
};

class SwordFactory : public IFactory{
    public:
    Sword* createItem() override;
};

class BowFactory : public IFactory{
    public:
    Bow* createItem() override;
};

class ShieldFactory : public IFactory{
    public:
    Shield* createItem() override;
};

int main(){
    SwordFactory* sword_factory = new SwordFactory();
    Sword* my_sword = sword_factory->createItem();
    std::cout << my_sword->name;
}

Sword* SwordFactory::createItem(){
    Sword* sword = new Sword();
    sword->name = "Sword";
    return sword;
}
