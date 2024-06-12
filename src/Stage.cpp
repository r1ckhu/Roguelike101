#include "Stage.hpp"

bool Stage::isWalkable(int x, int y) {
   if (!map->isWalkable(x, y)) {
      return false;
   }
   for (auto& actor : actors) {
      if (actor->x == x && actor->y == y) {
         return false;
      }
   }
   return true;
};