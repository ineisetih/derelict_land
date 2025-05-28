#ifndef SWORD_H
#define SWORD_H

#include "Weapon.h"
#include <vector>

class Sword : public Weapon {
  private:
  ItemType type = OneHandWeapon;
 public:
  // Конструктор меча.
  // name - имя меча.
  // damage - базовый урон меча.
  // slots - количество слотов для камней (по умолчанию 1).
  // gems - вектор указателей на камни для вставки в меч (по умолчанию пустой).
  Sword(std::string name, float damage, size_t slots = 1, std::vector<Gem*> gems = {});
  // Возвращает информацию о мече в виде строки.
  std::string GetInfo() override;
  // Возвращает тип предмета (OneHandWeapon).
  ItemType GetType() override;
};

#endif // SWORD_H
