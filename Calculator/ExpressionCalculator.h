#pragma once
#include <string>
#include <vector>
#include "BasicOperators.h"
#include "ICalculator.h"

using namespace std;

class BasicCalculator : public ICalculator
{
private:
	vector<double> values;
        vector<string> operators;

        void PopulateValuesVector();
    void PopulateOperatorVector();
       static BasicOperators StringToBasicOperators(const string& op);
    void Reset();

public:
    void CalculateResult() override;

};

