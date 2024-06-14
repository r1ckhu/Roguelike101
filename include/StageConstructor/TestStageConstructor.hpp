#pragma once
#include "StageConstructor.hpp"

class TestStageConstructor : public StageConstructor {
  public:
   void construct(Stage& dst) override final;
};