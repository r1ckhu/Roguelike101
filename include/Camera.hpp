#pragma once
#include <libtcod.hpp>

#include "Actor.hpp"
#include "GameMap.hpp"
#include "GetterSetter.h"
class Camera {
   Camera() = default;
   Camera(int viewport_x_, int viewport_y_)
       : viewport_x(viewport_x_),
         viewport_y(viewport_y_),
         camera_console(viewport_x_, viewport_y_) {}
   void set_follower(Actor* follower_) {
      follower = follower_;
      center_x = follower_->x;
      center_y = follower_->y;
   }
   DEFINE_SETTER(GameMap*, game_map)
   DEFINE_SETTER(int, viewport_x);
   DEFINE_SETTER(int, viewport_y);
   DEFINE_SETTER(int, center_x);
   DEFINE_SETTER(int, center_y);
   tcod::Console* render();

  private:
   int viewport_x, viewport_y;
   int center_x, center_y;
   tcod::Console camera_console;
   GameMap* game_map;
   Actor* follower;
};