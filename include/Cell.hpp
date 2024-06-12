#pragma once
#include <optional>

#include "Property.hpp"

class Cell {
  public:
   Cell() = default;
   Cell(char glyph_, bool is_walkable_ = true, bool is_transparent_ = true)
       : glyph(glyph_),
         property(std::nullopt),
         is_walkable(is_walkable_),
         is_transparent(is_transparent_) {}
   Cell(Property property_)
       : glyph(' '),
         property(property_),
         is_walkable(property_.get_is_walkable()),
         is_transparent(property_.get_is_transparent()){};

   char getGlyph() {
      return (property.has_value() ? property->getGlyph() : glyph);
   };
   bool isWalkable() {
      return (property.has_value() ? property->get_is_walkable() : is_walkable);
   }
   bool isTransparent() {
      return (property.has_value() ? property->get_is_transparent()
                                   : is_transparent);
   }

  private:
   char glyph;
   std::optional<Property> property;
   bool is_walkable;
   bool is_transparent;
};