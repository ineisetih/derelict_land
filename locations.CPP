#include "locations.h"

Locations::Locations (LocationType type, WeatherType weater) : type(type), weather(weater){}

LocationType Locations::GetType(){
    return type;
}
WeatherType Locations::GetWeather(){
    return weather;
}
std::vector<std::string> Locations::GetProperties(){
    return properties;
}

void Locations::AddProperty(const std::string& property){
    properties.emplace_back(property);
}

void Locations::DisplayInfo(){
  std::string LocationName;
  switch (type) {
    case DESERT: LocationName = "DESERT"; break;
    case FOREST: LocationName = "FOREST"; break;
    case FIELD: LocationName = "FIELD"; break;  
    default: LocationName = "IDK"; break;
  }

  std::string WeatherName;
  switch (weather) {
    case RAIN: LocationName = "RAIN"; break;
    case SUN: LocationName = "SUN"; break;
    case SNOW: LocationName = "SNOW"; break;  
    default: LocationName = "IDK"; break;
  }

  std::cout <<"Welcome to "<< LocationName << " !" << "\n";
  std::cout <<"Weather "<< WeatherName << "\n";
  std::cout <<"Properties:  "<< "\n";
  for (auto property : properties) {
    std::cout << property << "\n";
  }
  std::cout << "\n";
}

std::shared_ptr<Locations> LocationGenerator::GnerateLocation(){
    std::srand(std::time(0)); // Инициализация генератора случайных чисел

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