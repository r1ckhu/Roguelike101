#pragma once
#include "MapGenerator.hpp"

class BlankMapGenerator : public MapGenerator {
  public:
   void generate(GameMap& target_map) override final;
};