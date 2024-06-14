#pragma once
#include <libtcod.hpp>

#include "GetterSetter.h"
#include "Tile.hpp"
class Property {
  public:
   Property(char glyph_, bool is_walkable_ = true, bool is_transparent_ = true)
       : tile(glyph_),
         is_walkable(is_walkable_),
         is_transparent(is_transparent_) {}
   Tile& getTile() { return tile; }
   DEFINE_GETTER_SETTER(bool, is_walkable);
   DEFINE_GETTER_SETTER(bool, is_transparent);

  private:
   Tile tile;
   bool is_walkable;
   bool is_transparent;
};