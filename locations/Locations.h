#ifndef LOCATIONS_H
#define LOCATIONS_H

#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <memory>
#include <string>

enum LocationType { DESERT, FOREST, FIELD, LOCATION_TYPE_COUNT };

enum WeatherType { RAIN, SUN, SNOW, WEATHER_TYPE_COUNT };

class Locations {
 private:
  LocationType type;
  WeatherType weather;
  std::vector<std::string> properties; 

 public:
  // Конструктор локации.
  // type - тип локации (например, DESERT, FOREST).
  // weather - тип погоды в локации (например, RAIN, SUN).
  Locations(LocationType type, WeatherType weater);
  // Добавляет свойство (особенность) к локации.
  void AddProperty(const std::string& property);  
  // Возвращает тип локации.
  LocationType GetType();
  // Возвращает погоду в локации.
  WeatherType GetWeather();
  // Возвращает список свойств локации.
  std::vector<std::string> GetProperties();
  // Проверяет, обладает ли локация указанным свойством.
  bool HasProperty(const std::string& property);  

  // Отображает информацию о локации в консоль.
  void DisplayInfo();  
};

#endif  // LOCATIONS_H