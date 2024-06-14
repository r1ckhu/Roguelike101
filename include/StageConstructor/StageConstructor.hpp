#pragma once
#include "Stage.hpp"
class StageConstructor {
  public:
   virtual ~StageConstructor() = default;
   virtual void construct(Stage& stage) = 0;
};