#pragma once
#include <memory>

#include "Property.hpp"

class Cell {
  public:
   Cell() = default;
   Cell(char glyph_) : glyph(glyph_), property(nullptr) {}
   Cell(std::unique_ptr<Property> property_)
       : glyph(' '), property(std::move(property_)){};
   char getGlyph() {
      return (property == nullptr ? glyph : property->getGlyph());
   };

  private:
   char glyph;
   std::unique_ptr<Property> property;
};