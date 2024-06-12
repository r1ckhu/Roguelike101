#pragma once
#include "GetterSetter.h"
class Property {
  public:
   Property(char glyph_, bool is_walkable_ = true, bool is_transparent_ = true)
       : glyph(glyph_),
         is_walkable(is_walkable_),
         is_transparent(is_transparent_) {}
   char getGlyph() { return glyph; }
   DEFINE_GETTER_SETTER(bool, is_walkable);
   DEFINE_GETTER_SETTER(bool, is_transparent);

  private:
   char glyph;
   bool is_walkable;
   bool is_transparent;
};