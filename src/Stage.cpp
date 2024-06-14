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

Tile& Stage::getTile(int x, int y) {
   auto actor = getActorAt(x, y);
   if (actor) {
      return actor->tile;
   } else {
      return getCellAt(x, y).getTile();
   }
}

Cell& Stage::getCellAt(int x, int y) { return map->getCell(x, y); }

Actor* Stage::getActorAt(int x, int y) {
   for (auto& actor : actors) {
      if (actor->x == x && actor->y == y) {
         return actor.get();
      }
   }
   return nullptr;
}