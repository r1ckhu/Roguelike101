#pragma once
#include <memory>
#include <vector>

#include "Actor/Actor.hpp"
#include "GameMap.hpp"
#include "GameMath.hpp"

class Stage {
  public:
   Actor* getActorAt(p2i position);
   Cell* getCellAt(p2i position);
   void addActor(std::unique_ptr<Actor> actor) {
      actors.push_back(std::move(actor));
   }
   GameMap& getGameMap() { return *map; }
   bool isWalkable(int x, int y);

  private:
   std::vector<std::unique_ptr<Actor>> actors;
   std::unique_ptr<GameMap> map;
};