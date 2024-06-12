#pragma once
#include "MapGenerator.hpp"

class BlankMapGenerator : MapGenerator {
  public:
   void generate(GameMap& target_map) override final;
};