#pragma once
#include <memory>

#include "Camera.hpp"
#include "GameContext.hpp"
#include "Stage.hpp"

class Game {
  public:
   Game(std::unique_ptr<GameContext> _game_context,
        std::unique_ptr<Stage> _stage, std::unique_ptr<Camera> _camera)
       : game_context(std::move(_game_context)),
         stage(std::move(_stage)),
         camera(std::move(_camera)) {}

   void loop_once();

  private:
   std::unique_ptr<GameContext> game_context;
   std::unique_ptr<Stage> stage;
   std::unique_ptr<Camera> camera;
};