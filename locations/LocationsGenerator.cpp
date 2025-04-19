#include "LocationsGenerator.h"

std::shared_ptr<Locations> LocationGenerator::GenerateLocation() {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distrib_type(0, LOCATION_TYPE_COUNT - 1);
  std::uniform_int_distribution<> distrib_weather(0, WEATHER_TYPE_COUNT - 1);

  LocationType type = static_cast<LocationType>(distrib_type(gen));
  WeatherType weather = static_cast<WeatherType>(distrib_weather(gen));

  return std::make_shared<Locations>(type, weather);
}
