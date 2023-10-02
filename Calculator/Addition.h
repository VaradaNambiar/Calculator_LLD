#pragma once
#include "IOperation.h"
class Addition : public IOperation
{
public:
  double calculate(double lhs, double rhs) override;
};
