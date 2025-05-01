#ifndef LOCATIONSGENERATOR_H
#define LOCATIONSGENERATOR_H

#include "Locations.h"
#include <random>

class LocationGenerator {
 public:
  LocationGenerator() = delete;
  static std::shared_ptr<Locations> GenerateLocation();
};

#endif // LOCATIONSGENERATOR_H
