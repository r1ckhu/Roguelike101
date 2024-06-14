#pragma once
#include <optional>

#include "Property.hpp"
#include "Tile.hpp"
class Cell {
  public:
   Cell() = default;
   Cell(char glyph_, bool is_walkable_ = true, bool is_transparent_ = true)
       : tile(glyph_),
         property(std::nullopt),
         is_walkable(is_walkable_),
         is_transparent(is_transparent_) {}
   Cell(Property property_)
       : tile(' '),
         property(property_),
         is_walkable(property_.get_is_walkable()),
         is_transparent(property_.get_is_transparent()){};

   Tile& getTile() {
      return (property.has_value() ? property->getTile() : tile);
   };
   bool isWalkable() {
      return (property.has_value() ? property->get_is_walkable() : is_walkable);
   }
   bool isTransparent() {
      return (property.has_value() ? property->get_is_transparent()
                                   : is_transparent);
   }

  private:
   Tile tile;
   std::optional<Property> property;
   bool is_walkable;
   bool is_transparent;
};