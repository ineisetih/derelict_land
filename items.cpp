#include <iostream>
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

class WeaponGenerator{
    public:
    virtual Weapon* CreateWeapon(std::string name, float damage) = 0;
    virtual ~WeaponGenerator() = default;
};

class SwordGenerator : public WeaponGenerator {
    public:
    Weapon* CreateWeapon(std::string name, float damage) override {
        return new Sword(name, damage);
    }
};


class Sword : public Weapon {
    public:
    Sword(std::string name, float damage);
};

void Test(IItem* item){
    item->GetInfo();
}

int main(){
    Sword* sword = new Sword("Sara", 10);
    sword->GetInfo();
    Test(sword);
    return 0;
}

void Weapon::GetInfo() {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Damage: " << damage << std::endl;
}

Sword::Sword(std::string name, float damage){
    this->name = name;
    this->damage = damage;
}


