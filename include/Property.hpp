#pragma once

class Property {
  public:
   Property(char glyph_) : glyph(glyph_) {}
   char getGlyph() { return glyph; }

  private:
   char glyph;
};