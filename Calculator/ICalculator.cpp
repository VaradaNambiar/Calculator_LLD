#include "ICalculator.h"

#include <iostream>

using namespace std;

void ICalculator::SetExpression(string statement) { expression = statement; }

double ICalculator::GetResult() { return result; }

void ICalculator::Reset() {
  result = 0.;
  expression = "";
}

const string ICalculator::GetExpression() { return expression; }

string ICalculator::GetCalculation(int id, string file_path) {
  string result_expression;
  if (fileOperations.ReadCalc(id, file_path, result_expression)!=0)
    result_expression = "File does not exist";
  return result_expression;
}

void ICalculator::SaveCalculation() {
  cout << "FileLocation:";
  string input_path;
  cin >> input_path;
  string entire_line = GetExpression() + "=" + to_string(result);
  if (fileOperations.WriteTo(input_path, entire_line) == 0)
    cout << "Successfully saved!" << endl;
  else
    cout << "Error in saving" << endl;
}

string ICalculator::GetLastCalculation(string file_path) {
  const int last_line_id = fileOperations.GetHighestId();
   string return_expression = GetCalculation(last_line_id, file_path);
  return return_expression;
}

string ICalculator::GetFileLocation() { return fileOperations.GetPath(); }

void ICalculator::ViewAllCalcs() const { fileOperations.ViewHistory(); }
