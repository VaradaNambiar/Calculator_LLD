#pragma once
#include "IOperation.h"
class Multiplication : public IOperation
{
 public:
  double calculate(double lhs, double rhs) override;
};
