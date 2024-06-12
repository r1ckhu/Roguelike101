#include <SDL.h>

#include <libtcod.hpp>
#include <memory>

#include "Game.hpp"
#include "GameContext.hpp"
std::unique_ptr<GameContext> initContext() {
   GameContext game_context;
   const char* const tileset_path = "data/fonts/terminal16x16_gs_ro.png";
   game_context.tileset =
       tcod::load_tilesheet(tileset_path, {16, 16}, tcod::CHARMAP_CP437);
   game_context.console = tcod::Console{80, 50};
   game_context.context_params.tcod_version = TCOD_COMPILEDVERSION;
   game_context.context_params.renderer_type = TCOD_RENDERER_SDL2;
   game_context.context_params.tileset = game_context.tileset.get();
   game_context.context_params.vsync = 0;
   game_context.context_params.sdl_window_flags = SDL_WINDOW_RESIZABLE;
   game_context.context_params.window_title = "Roguelike101";
   game_context.context_params.console = game_context.console.get();
   game_context.context = tcod::Context(game_context.context_params);
   return std::make_unique<GameContext>(std::move(game_context));
}

int main() {
   SDL_LogSetAllPriority(SDL_LOG_PRIORITY_WARN);
   auto game_context = initContext();
   Game game(std::move(game_context));
   game.loop();
   atexit(TCOD_quit);
   return 0;
}
