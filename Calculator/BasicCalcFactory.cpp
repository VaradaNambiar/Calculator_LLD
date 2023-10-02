#include "BasicCalcFactory.h"
#include "ExpressionCalculator.h"


ICalculator* BasicCalcFactory::createCalculator() {
  return new BasicCalculator();
}
