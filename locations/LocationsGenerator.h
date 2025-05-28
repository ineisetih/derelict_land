#ifndef LOCATIONSGENERATOR_H
#define LOCATIONSGENERATOR_H

#include "Locations.h"
#include <random>

class LocationGenerator {
 public:
  // Удаленный конструктор по умолчанию, чтобы класс нельзя было инстанциировать.
  LocationGenerator() = delete;
  // Статический метод для генерации случайной локации.
  static std::shared_ptr<Locations> GenerateLocation();
};

#endif // LOCATIONSGENERATOR_H
