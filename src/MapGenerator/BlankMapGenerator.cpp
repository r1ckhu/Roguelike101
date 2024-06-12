#include "MapGenerator/BlankMapGenerator.hpp"

void BlankMapGenerator::generate(GameMap& dst) {
   GameMap::MapData new_data(dst.get_y_size(),
                             std::vector<Cell>(dst.get_x_size()));
   for (auto& row : new_data) {
      std::fill(row.begin(), row.end(), Cell('.'));
   }
   dst.setMapData(std::move(new_data));
}