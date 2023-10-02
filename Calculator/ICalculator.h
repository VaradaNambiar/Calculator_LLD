#pragma once
#include <string>

#include "Persistence.h"

using namespace std;

class ICalculator
{
 private:
  string expression;

 protected:
  double result;
  Persistence fileOperations;


 public:
  void SetExpression(string statement);
  double GetResult();
  void Reset();
  virtual void CalculateResult()=0;
  const string GetExpression();
   string GetCalculation(int id, string file_path) ;
  void SaveCalculation();
  string GetLastCalculation(string file_path);
  string GetFileLocation();
  void ViewAllCalcs() const;
};


