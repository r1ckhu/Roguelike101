#include <SDL.h>

#include <libtcod.hpp>
#include <memory>

#include "Camera.hpp"
#include "Game.hpp"
#include "GameContext.hpp"
#include "StageConstructor/TestStageConstructor.hpp"

std::unique_ptr<GameContext> initContext(int argc, char* argv[]) {
   std::unique_ptr<GameContext> game_context = std::make_unique<GameContext>();
   const char* const tileset_path = "../data/fonts/terminal16x16_gs_ro.png";
   game_context->tileset =
       tcod::load_tilesheet(tileset_path, {16, 16}, tcod::CHARMAP_CP437);
   game_context->console = tcod::Console{80, 50};
   game_context->context_params.tcod_version = TCOD_COMPILEDVERSION;
   game_context->context_params.renderer_type = TCOD_RENDERER_SDL2;
   game_context->context_params.tileset = game_context->tileset.get();
   game_context->context_params.vsync = 0;
   game_context->context_params.sdl_window_flags = SDL_WINDOW_RESIZABLE;
   game_context->context_params.window_title = "Roguelike101";
   game_context->context_params.console = game_context->console.get();
   game_context->context_params.argc = argc;
   game_context->context_params.argv = argv;
   game_context->context = tcod::Context(game_context->context_params);
   return game_context;
}

int main(int argc, char* argv[]) {
   auto game_context = initContext(argc, argv);

   std::unique_ptr<StageConstructor> stage_constructor =
       std::make_unique<TestStageConstructor>();
   std::unique_ptr<Stage> stage = std::make_unique<Stage>();
   stage_constructor->construct(*stage.get());

   std::unique_ptr<Camera> camera = std::make_unique<Camera>(30, 30);
   camera->set_follower(&stage->getPlayer());
   camera->set_stage(stage.get());
   Game game(std::move(game_context), std::move(stage), std::move(camera));

   while (true) {
      game.loop_once();
   }
   return 0;
}
