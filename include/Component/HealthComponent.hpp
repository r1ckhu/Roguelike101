#pragma once
#include "GetterSetter.h"
class HealthComponent {
  public:
   HealthComponent() = default;
   HealthComponent(int health_) : health(health_){};
   DEFINE_GETTER_SETTER(int, health);

  private:
   int health;
};