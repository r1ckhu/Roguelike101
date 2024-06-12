#pragma once
#include "GameMap.hpp"

class MapGenerator {
  public:
   virtual void generate(GameMap& target_map) = 0;
};