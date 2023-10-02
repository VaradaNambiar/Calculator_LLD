#pragma once
#include "IOperation.h"
class Division : public IOperation
{
 public:
  double calculate(double lhs, double rhs) override;
};
