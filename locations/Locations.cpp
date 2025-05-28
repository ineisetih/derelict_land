#include "Locations.h"
#include <iostream>  // Для std::cout

// Конструктор класса Locations.
// Инициализирует локацию с указанным типом и погодой.
Locations::Locations(LocationType type, WeatherType weather) : type(type), weather(weather) {
}

// Добавляет свойство (особенность) к локации.
void Locations::AddProperty(const std::string& property) {
  properties.push_back(property);
}

// Возвращает тип локации.
LocationType Locations::GetType() {
  return type;
}

// Возвращает текущую погоду в локации.
WeatherType Locations::GetWeather() {
  return weather;
}

// Возвращает вектор строк, содержащий все свойства локации.
std::vector<std::string> Locations::GetProperties() {
  return properties;
}

// Проверяет, обладает ли локация указанным свойством.
bool Locations::HasProperty(const std::string& property) {
  for (const auto& prop : properties) {
    if (prop == property) {
      return true;
    }
  }
  return false;
}

// Выводит информацию о локации (тип, погода и свойства) в консоль.
void Locations::DisplayInfo() {
  std::cout << "Location Type: " << type << ", Weather: " << weather << std::endl;
  std::cout << "Properties: ";
  for (const auto& prop : properties) {
    std::cout << prop << "; ";
  }
  std::cout << std::endl;
}