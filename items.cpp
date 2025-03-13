#ifndef ITEMSCPP
#define ITEMSCPP

#include "items.h"

#include <iostream>
#include <string>
#include <array>




// class WeaponGenerator{
//     public:
//     virtual Weapon* CreateWeapon(std::string name, float damage) = 0;
//     virtual ~WeaponGenerator() = default;
// };

// class SwordGenerator : public WeaponGenerator {
//     public:
//     Weapon* CreateWeapon(std::string name, float damage) override {
//         return new Sword(name, damage);
//     }
// };
// void Test(IItem* item){
//     item->GetInfo();
// }

void Weapon::GetInfo() {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Damage: " << damage << std::endl;
}

Sword::Sword(std::string name, float damage){
    this->name = name;
    this->damage = damage;
}



#endif // ITEMSCPP