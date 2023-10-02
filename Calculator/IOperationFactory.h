#pragma once
#include "BasicOperators.h"
#include "IOperation.h"
#include <string>

using namespace std;

class IOperationFactory
{
public:
   static IOperation* createOperator(BasicOperators oper);
};
