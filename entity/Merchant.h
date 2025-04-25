#ifndef MERCHANT_H
#define MERCHANT_H

#include "NPC.h"

class Merchant : public NPC {
 public:
  Merchant(std::string name, float health, float damage);
  void Interact() override;
};

#endif // MERCHANT_H
