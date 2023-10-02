#pragma once

#include "ExpressionCalculator.h"

#include <exception>
#include <iostream>
#include <regex>

#include "IOperation.h"
#include "IOperationFactory.h"

void BasicCalculator::PopulateValuesVector() {
  values.clear();
 // std::regex regex("([0-9]+.)");
  std::regex regex(R"(\d+(\.\d+)?)");
  const string expression = GetExpression();
  auto values_iterator =
      std::sregex_iterator(expression.begin(), expression.end(), regex);
  auto end = std::sregex_iterator();

  for (; values_iterator != end; ++values_iterator) {
    values.push_back(stod(values_iterator->str()));
  }
}

void BasicCalculator::PopulateOperatorVector() {
  operators.clear();
  std::regex regex("([-+*/cC])");  // TODO: Handle symbols other than these

    const string expression = GetExpression();
  auto operator_iterator =
      std::sregex_iterator(expression.begin(), expression.end(), regex);
  auto end = std::sregex_iterator();

  for (; operator_iterator != end; ++operator_iterator) {
    operators.push_back(operator_iterator->str());
  }
}

BasicOperators BasicCalculator::StringToBasicOperators(const string& op) {
  if (op == "+")
    return BasicOperators::PLUS;
  else if (op == "-")
    return BasicOperators::MINUS;
  else if (op == "*")
    return BasicOperators::INTO;
  else if (op == "/")
    return BasicOperators::BY;
  else if (op == "c" || op == "C")
    return BasicOperators::C;
  else if (op == "=")
    return BasicOperators::EQUAL;
  else
    std::exception("Invalid basic operator");
}

void BasicCalculator::Reset() {
  ICalculator::Reset();
  values.clear();
  operators.clear();
}




void BasicCalculator::CalculateResult() {
  PopulateValuesVector();
  PopulateOperatorVector();

  if (values.size() != operators.size() + 1) {
    std::exception("Input wrong");
  }
  for (int i = 0; i < values.size() - 1; i++) {
    int j = i + 1;
    string operation = operators[i];
    if (operation == "C" || operation == "c") {
      Reset(); // TODO:C not working as expected
      break;
    }
    IOperation* calculation = IOperationFactory::createOperator(
        BasicCalculator::StringToBasicOperators(operation));
    values[j] = calculation->calculate(values[i], values[j]);
  }
  result = values[values.size() - 1];
}

