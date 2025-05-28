#ifndef ARMOR_H
#define ARMOR_H

#include "ItemInteface.h"
#include "Gems.h"
#include <vector>

class Armor : public IItem {
 protected:
  std::string name;
  std::vector<Gem*> gems;
  float defence;
  size_t number_of_gem_slots;

 public:
  // Возвращает информацию о броне в виде строки.
  std::string GetInfo() override;
  // Деструктор. Освобождает память, занятую камнями.
  ~Armor();
  // Конструктор брони.
  // name - имя брони.
  // defence - базовое значение защиты.
  // slots - количество слотов для камней.
  Armor(const std::string name, float defence, size_t slots);
  // Добавляет камень в броню.
  void AddGem(Gem* gem);
  // Удаляет камень из брони.
  void RemoveGem(Gem* gem);
};

#endif // ARMOR_H
