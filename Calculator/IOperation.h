#pragma once
class IOperation
{
public:
  virtual double calculate(double lhs=0, double rhs=0) = 0;
};
