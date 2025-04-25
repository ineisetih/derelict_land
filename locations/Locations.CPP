#include "locations.h"
#include <algorithm>

Locations::Locations(LocationType type, WeatherType weater) : type(type), weather(weater) {
}

LocationType Locations::GetType() {
  return type;
}
WeatherType Locations::GetWeather() {
  return weather;
}
std::vector<std::string> Locations::GetProperties() {
  return properties;
}

void Locations::AddProperty(const std::string& property) {
  properties.emplace_back(property);
}

void Locations::DisplayInfo() {
  std::string LocationName;
  switch (type) {
    case DESERT:
      LocationName = "DESERT";
      break;
    case FOREST:
      LocationName = "FOREST";
      break;
    case FIELD:
      LocationName = "FIELD";
      break;
    default:
      LocationName = "IDK";
      break;
  }

  std::string WeatherName;
  switch (weather) {
    case RAIN:
      WeatherName = "RAIN";
      break;
    case SUN:
      WeatherName = "SUN";
      break;
    case SNOW:
      WeatherName = "SNOW";
      break;
    default:
      WeatherName = "IDK";
      break;
  }

  std::cout << "Welcome to " << LocationName << " !" << "\n";
  std::cout << "Weather " << WeatherName << "\n";
  std::cout << "Properties:  " << "\n";
  for (auto property : properties) {
    std::cout << property << "\n";
  }
  std::cout << "\n";
}

bool Locations::HasProperty(const std::string& property) {
  return std::find(properties.begin(), properties.end(), property) != properties.end();
}