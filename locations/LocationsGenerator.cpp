#include "LocationsGenerator.h"

std::shared_ptr<Locations> LocationGenerator::GenerateLocation() {
  std::srand(std::time(0));  // Инициализация генератора случайных чисел

  // Случайный выбор типа локации
  LocationType RandomType = static_cast<LocationType>(std::rand() % LOCATION_TYPE_COUNT);

  // Случайный выбор погоды
  WeatherType RandomWeather = static_cast<WeatherType>(std::rand() % WEATHER_TYPE_COUNT);

  // Создание локации
  auto location = std::make_shared<Locations>(RandomType, RandomWeather);

  // Добавление случайных свойств ///
  if (std::rand() % 2 == 0) {
    location->AddProperty("Enemies nearby");
  }
  if (std::rand() % 2 == 0) {
    location->AddProperty("Treasure hidden");
  }
  if (std::rand() % 2 == 0) {
    location->AddProperty("Safe zone");
  }
  return location;
}
