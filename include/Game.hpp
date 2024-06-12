#pragma once
#include <memory>

#include "GameContext.hpp"
#include "Stage.hpp"
class Game {
  public:
   Game(std::unique_ptr<GameContext> _game_context,
        std::unique_ptr<Stage> _stage)
       : game_context(std::move(_game_context)), stage(std::move(_stage)) {}

   void loop();

  private:
   std::unique_ptr<GameContext> game_context;
   std::unique_ptr<Stage> stage;
};