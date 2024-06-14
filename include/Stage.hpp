#pragma once
#include <memory>
#include <vector>

#include "Actor/Actor.hpp"
#include "Actor/Player.hpp"
#include "GameMap.hpp"

class Stage {
  public:
   Actor* getActorAt(int x, int y);
   Cell& getCellAt(int x, int y);
   void addActor(std::unique_ptr<Actor> actor) {
      actors.push_back(std::move(actor));
   }
   void setGameMap(std::unique_ptr<GameMap> map_) { map = std::move(map_); }
   GameMap& getGameMap() { return *map; }
   std::vector<std::unique_ptr<Actor>>& getActors() { return actors; }
   bool isWalkable(int x, int y);
   Tile& getTile(int x, int y);
   void setPlayer(std::unique_ptr<Player> player_) {
      player = std::move(player_);
   }
   Player& getPlayer() { return *player; }

  private:
   std::vector<std::unique_ptr<Actor>> actors;
   std::unique_ptr<GameMap> map;
   std::unique_ptr<Player> player;
};