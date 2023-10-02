#pragma once
#include "ICalculatorFactory.h"
#include "ExpressionCalculator.h"
class BasicCalcFactory : public ICalculatorFactory
{
public:
  ICalculator* createCalculator() override;
};
