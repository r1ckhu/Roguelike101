#include "StageConstructor/TestStageConstructor.hpp"

#include "MapGenerator/BlankMapGenerator.hpp"

void TestStageConstructor::construct(Stage& dst) {
   BlankMapGenerator bmg;
   std::unique_ptr<GameMap> new_game_map = std::make_unique<GameMap>(100, 100);
   bmg.generate(*new_game_map);
   dst.setGameMap(std::move(new_game_map));
   std::unique_ptr<Player> new_player = std::make_unique<Player>(100);
   new_player->x = 10;
   new_player->y = 10;
   dst.setPlayer(std::move(new_player));
}