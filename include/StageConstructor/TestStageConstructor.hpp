#pragma once
#include "StageConstructor.hpp"

class TestStageConstructor : StageConstructor {
  public:
   void construct(Stage& dst) override final;
};