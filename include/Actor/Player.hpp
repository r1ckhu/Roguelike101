#pragma once
#include "Actor.hpp"
#include "Component/HealthComponent.hpp"

class Player : Actor {
  public:
   Player();
   Player(int health);
   void process(Stage* game_info) override final;
   void processInput(Stage* game_info, SDL_Event& event) override final;

  private:
   std::shared_ptr<HealthComponent> health_comp;
   void tryMoving(Stage* game_info, int dx, int dy);
};