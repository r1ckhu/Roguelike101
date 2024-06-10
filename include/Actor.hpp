#pragma once
#include <SDL.h>
class Action;
class Stage;
class Actor {
  public:
   virtual void onInteract(Action* action) = 0;
   virtual void process(Stage* game_info, SDL_Event event) = 0;
};