#include "Game.hpp"

void Game::loop_once() {
   SDL_Event event;
   while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
         std::exit(0);
      }
      stage->getPlayer().processInput(stage.get(), event);
   }
   auto console = camera->render();
   game_context->context.present(*console);
}