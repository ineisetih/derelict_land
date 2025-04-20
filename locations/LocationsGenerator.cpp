#include "LocationsGenerator.h"

// std::shared_ptr<Locations> LocationGenerator::GenerateLocation() {
//   std::random_device rd;
//   std::mt19937 gen(rd());
//   std::uniform_int_distribution<> distrib_type(0, LOCATION_TYPE_COUNT - 1);
//   std::uniform_int_distribution<> distrib_weather(0, WEATHER_TYPE_COUNT - 1);

//   LocationType type = static_cast<LocationType>(distrib_type(gen));
//   WeatherType weather = static_cast<WeatherType>(distrib_weather(gen));

//   return std::make_shared<Locations>(type, weather);
// }

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
