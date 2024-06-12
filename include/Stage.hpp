#pragma once
#include <memory>
#include <vector>

#include "Actor.hpp"
#include "GameMap.hpp"
#include "GameMath.hpp"

class Stage {
  public:
   Actor* getActorAt(p2i position);
   Cell* getCellAt(p2i position);
   void addActor(std::unique_ptr<Actor> actor) { actors.push_back(actor); }
   GameMap& getGameMap() { return map; }

  private:
   std::vector<std::unique_ptr<Actor>> actors;
   GameMap map;
};