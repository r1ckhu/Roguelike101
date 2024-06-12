#include "StageConstructor/TestStageConstructor.hpp"

#include "MapGenerator/BlankMapGenerator.hpp"

void TestStageConstructor::construct(Stage& dst) {
   BlankMapGenerator bmg;
   std::unique_ptr<GameMap> new_game_map = std::make_unique<GameMap>(100, 100);
   bmg.generate(*new_game_map);
}