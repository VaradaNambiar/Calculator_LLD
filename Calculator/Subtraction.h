#pragma once
#include "IOperation.h"
class Subtraction : public IOperation
{
 public:
  double calculate(double lhs, double rhs) override;
};
