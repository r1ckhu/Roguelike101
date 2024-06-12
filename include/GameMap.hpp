#pragma once
#include <stdexcept>
#include <vector>

#include "Cell.hpp"
#include "GetterSetter.h"

class GameMap {
  public:
   using MapData = std::vector<std::vector<Cell>>;
   // In this map, the origin (0,0) is at the top-left corner.
   // The vertical coordinate is 'y', and the horizontal coordinate is 'x'.
   GameMap(int x_size_, int y_size_) : x_size(x_size_), y_size(y_size_) {
      map_data = MapData(y_size, std::vector<Cell>(x_size));
   };

   bool testInside(int x, int y) {
      return x >= 0 && y >= 0 && x < x_size && y < y_size;
   }

   char getGlyph(int x, int y) {
      if (!testInside(x, y)) {
         throw std::runtime_error("GameMap: Out of bound.");
      }
      return map_data[y][x].getGlyph();
   };

   Cell& getCell(int x, int y) {
      if (!testInside(x, y)) {
         throw std::runtime_error("GameMap: Out of bound.");
      }
      return map_data[y][x];
   }

   void setMapData(MapData new_map_data) { map_data = std::move(new_map_data); }

   bool isWalkable(int x, int y) {
      return testInside(x, y) && map_data[y][x].isWalkable();
   }
   bool isTransparent(int x, int y) {
      return testInside(x, y) && map_data[y][x].isTransparent();
   }

   DEFINE_GETTER(int, x_size);
   DEFINE_GETTER(int, y_size);

  private:
   MapData map_data;
   int x_size, y_size;
};