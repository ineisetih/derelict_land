#ifndef ITEM_INTERFACE_H
#define ITEM_INTERFACE_H

#include <string>

class IItem {
 public:
  virtual std::string GetInfo() = 0;
  virtual ~IItem() = default;
};

#endif // ITEM_INTERFACE_H
