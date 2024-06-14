#include "Camera.hpp"

tcod::Console* Camera::render() {
   center_x = follower->x;
   center_y = follower->y;
   int top_left_x = center_x - viewport_x / 2;
   int top_left_y = center_y - viewport_y / 2;
   for (int y = 0; y < viewport_y; ++y) {
      for (int x = 0; x < viewport_x; ++x) {
         int map_x_pos = top_left_x + x;
         int map_y_pos = top_left_y + y;
         if (!stage->getGameMap().testInside(map_x_pos, map_y_pos)) {
            camera_console.at(x, y) = Tile();
         } else {
            camera_console.at(x, y) =
                stage->getGameMap().getTile(map_x_pos, map_y_pos);
         }
      }
   }
   auto& actors = stage->getActors();
   for (auto& actor : actors) {
      int actor_console_x = actor->x - top_left_x;
      int actor_console_y = actor->y - top_left_y;
      if (actor_console_x >= 0 && actor_console_x < viewport_x && 
          actor_console_y >= 0 && actor_console_y < viewport_y) {
         camera_console.at(actor_console_x, actor_console_y) = actor->tile;
      }
   }
   
   auto& player = stage->getPlayer();
   int player_console_x = player.x - top_left_x;
   int player_console_y = player.y - top_left_y;
   if (player_console_x >= 0 && player_console_x < viewport_x && 
       player_console_y >= 0 && player_console_y < viewport_y) {
      camera_console.at(player_console_x, player_console_y) = player.tile;
   }

   return &camera_console;
};