#include "Actor/Player.hpp"

#include "Stage.hpp"

Player::Player(int health) {
   health_comp = std::make_shared<HealthComponent>(health);
   addComponent(health_comp);
}

Player::Player() : Player(0) {}

void Player::process(Stage* game_info) {}

void Player::processInput(Stage* game_info, SDL_Event& event) {
   switch (event.type) {
      case SDL_KEYDOWN:
         switch (event.key.keysym.sym) {
            case SDLK_w:
               tryMoving(game_info, 0, -1);  // player move north
               break;
            case SDLK_s:
               tryMoving(game_info, 0, 1);  // player move south
               break;
            case SDLK_a:
               tryMoving(game_info, -1, 0);  // player move west
               break;
            case SDLK_d:
               tryMoving(game_info, 1, 0);  // player move east
               break;
            default:
               break;
         }
         break;
      default:
         break;
   }
}

void Player::tryMoving(Stage* game_info, int dx, int dy) {
   int dst_x = x + dx;
   int dst_y = y + dy;
   if (game_info->isWalkable(x, y)) {
      x = dst_x;
      y = dst_y;
   }
}