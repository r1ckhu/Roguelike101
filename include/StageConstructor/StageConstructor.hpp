#pragma once
#include "Stage.hpp"
class StageConstructor {
  public:
   virtual void construct(Stage& stage) = 0;
};