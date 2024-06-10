#pragma once
#include <memory>
#include <vector>

#include "Actor.hpp"
#include "GameMap.hpp"
#include "GameMath.hpp"

class Stage {
  public:
   Actor* getActorAt(p2i position);

  private:
   std::vector<std::unique_ptr<Actor>> actors;
   GameMap map;
};