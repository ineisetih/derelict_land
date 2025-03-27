#ifndef ITEMS
#define ITEMS

#include <string>
#include <vector>

class IItem {
 public:
  virtual void GetInfo() = 0;
  virtual ~IItem() = default;
};

class Gem : public IItem {
  std::string type;
  float bonus;

 public:

  Gem(std::string type, float bonus) : type(type), bonus(bonus) {};


  std::string GetInfo() override;
};

class Weapon : public IItem {
 protected:
  std::string name;
  float damage;
  int number_of_gem_slots;
  std::vector<Gem*> gems;

 public:

  Weapon(std::string name, float damage, int slost) : name(name), damage(damage), number_of_gem_slots(slots) {
  };

  ~Weapon() override;
  std::string GetInfo() override;
  void AddGem(Gem* gem);
  void RemoveGem(Gem* gem);
};

class Armor : public IItem {
 protected:
  std::string name;
  std::vector<Gem*> gems;
  float defence;
  int number_of_gem_slots;

 public:
  std::string GetInfo() override;
  ~Armor() override;
  Armor(std::string name, float defence, int slots);
  void AddGem(Gem* gem);
  void RemoveGem(Gem* gem);
};

class Sword : public Weapon {
 public:
  Sword(std::string name, float damage, int slots = 1, std::vector<Gem*> gems = {});
  std::string GetInfo() override;
  void AddGem(Gem* gem);
  void RemoveGem(Gem* gem);
};

/*enum WeaponType {
  sword
};

enum ArmorType {
  helmet
};


class CreateWeapon {
  public:
  static std::shared_ptr<Weapon> Create(WeaponType type);
};

class CreateArmor {
  public:
  static std::shared_ptr<Armor> Create(ArmorType type);
<<<<<<< HEAD
}*/
;
=======
}*/;
>>>>>>> 55a9da078276bb05524960f840d324a1a0006a37

#endif  // ITEMS