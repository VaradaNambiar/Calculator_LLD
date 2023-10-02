#pragma once

#include "IOperationFactory.h"
#include "Addition.h"
#include "Division.h"
#include "Multiplication.h"
#include "Subtraction.h"
IOperation* IOperationFactory::createOperator(BasicOperators oper) {
  switch (oper) {
    case BasicOperators::PLUS:
      return new Addition();
      break;
    case BasicOperators::MINUS:
      return new Subtraction();
      break;
    case BasicOperators::INTO:
      return new Multiplication();
      break;
    case BasicOperators::BY:
      return new Division();
      break;
    default:
      std::exception("Invalid operator");
  }
}
