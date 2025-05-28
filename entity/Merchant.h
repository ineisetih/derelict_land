#ifndef MERCHANT_H
#define MERCHANT_H

#include "NPC.h"

class Merchant : public NPC {
 public:
  // Конструктор торговца.
  Merchant(std::string name, float health, float damage);
  // Переопределенный метод взаимодействия с торговцем.
  void Interact() override;
};

#endif // MERCHANT_H
