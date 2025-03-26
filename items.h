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
 public:
  void GetInfo() override;
  ~Gem() = default;
};

class Weapon : public IItem {
 protected:
  std::string name;
  float damage;
  int number_of_gem_slots;
  std::vector<Gem*> gems;

 public:
  Weapon(std::string name, float damage);
  void GetInfo() override;
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
  void GetInfo() override;
  Armor(std::string name, float defence);
};

class Sword : public Weapon {
 public:
  Sword(std::string name, float damage, int number_of_gem_slots, std::vector<Gem*> gems);
  Sword();
  ~Sword() = default;
};

enum WeaponType {
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
};

#endif // ITEMS
