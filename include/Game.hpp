#pragma once
#include <memory>

#include "GameContext.hpp"

class Game {
  public:
   Game(std::unique_ptr<GameContext> _game_context)
       : game_context(std::move(_game_context)) {}

   void loop();

  private:
   std::unique_ptr<GameContext> game_context;
};