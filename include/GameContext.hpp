#pragma once
#include <libtcod.hpp>

class GameContext {
  public:
   tcod::Context context;
   tcod::Console console;
   TCOD_ContextParams context_params;
   tcod::Tileset tileset;
};