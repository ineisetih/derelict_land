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
  Locations(LocationType type, WeatherType weater);
  void AddProperty(const std::string& property);  
  LocationType GetType();
  WeatherType GetWeather();
  std::vector<std::string> GetProperties();
  bool HasProperty(const std::string& property);  

  void DisplayInfo();  
};

#endif  // LOCATIONS_H