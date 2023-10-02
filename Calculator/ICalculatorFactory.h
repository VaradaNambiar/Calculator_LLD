#pragma once
#include "ICalculator.h"


using namespace std;

class ICalculatorFactory
{

public:
	virtual ICalculator* createCalculator() = 0;
};


// Scientific calc
//class ScientificCalcFactory : ICalculatorFactory
