#pragma once

#include <libtcod.hpp>

static constexpr auto WHITE = tcod::ColorRGB{255, 255, 255};
static constexpr auto BLACK = tcod::ColorRGB{0, 0, 0};

static constexpr auto GREY = tcod::ColorRGB{127, 127, 127};
static constexpr auto LIGHT_BLUE = tcod::ColorRGB{63, 63, 255};
static constexpr auto LIGHT_YELLOW = tcod::ColorRGB{255, 255, 63};

class Tile {
  public:
   operator TCOD_ConsoleTile() const { return TCOD_ConsoleTile{ch, fg, bg}; }
   Tile() : ch(' '), fg(WHITE), bg(BLACK) {}
   Tile(int ch_) : ch(ch_), fg(WHITE), bg(BLACK) {}
   Tile(int ch_, TCOD_ColorRGBA fg_, TCOD_ColorRGBA bg_)
       : ch(ch_), fg(fg_), bg(bg_) {}

  public:
   int ch;
   TCOD_ColorRGBA fg;
   TCOD_ColorRGBA bg;
};