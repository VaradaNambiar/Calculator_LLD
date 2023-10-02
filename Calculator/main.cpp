// Calculator.cpp : This file contains the 'main' function. Program execution
// begins and ends there.
//
#pragma once
#include <iostream>

#include "BasicCalcFactory.h"
#include "Display.h"
#include "ExpressionCalculator.h"
#include "ICalculatorFactory.h"

using namespace std;

void DisplayCalculatorUI();
void CheckPersistence();
void DisplayMenu();
bool IsUserRequestMenu(string user_input);
int HandleMenu(string user_selection);
int recursiveImplementation(ICalculator* calc);
void ResetGlobals();

bool is_save = false;
bool is_retreive = false;
bool is_new = true;
bool is_view_history = false;
int retrieve_id = -1;

int main() {
  string user_menu_input = "";
  cout << "Basic calculator" << endl;
  ICalculatorFactory* calcFactory = new BasicCalcFactory();
  ICalculator* calculator = calcFactory->createCalculator();
  return (recursiveImplementation(calculator));
    //TODO: make it work for a mix of decimals and ints
}

void DisplayCalculatorUI() {
  cout << "|"
       << "    AC     *" << endl;
  cout << "|"
       << "  1  2  3  +" << endl;
  cout << "|"
       << "  4  5  6  -" << endl;
  cout << "|"
       << "  7  8  9  /" << endl;
  cout << "|"
       << "    0   .  =" << endl;
}

void DisplayMenu() {  // could use Commad design pattern?
  cout << "MENU:" << endl;
  cout << "0: Cancel" << endl;
  cout << "1: Retrieve" << endl;
  cout << "2: Save" << endl;
  cout << "3: New" << endl;
  cout << "4: View Calculation History" << endl;
  cout << "-1: End Application" << endl;
}

bool IsUserRequestMenu(string user_input) {
  if (user_input.compare("M") == 0 || user_input.compare("m") == 0) return true;
  return false;
}

int HandleMenu(string user_input) {
  if (IsUserRequestMenu(user_input)) {
    DisplayMenu();
    int user_option;
    cin >> user_option;
    switch (user_option) {
      case 1:
        is_retreive = true;
        cout << "enter the line you want to retrieve";
        cin >> retrieve_id; // TODO: when retrieve before saving 
        break;
      case 2:
        is_save = true;
        break;
      case -1:
        return -1;
      case 3:
        is_new = true;
        break;
    case 4:
        is_view_history = true;
        break;
      default:
        is_new = false;
        return 0;
    }
  }
  return 0; // not work for enter
}

int recursiveImplementation(ICalculator* calculator) {
  if (is_new) {
    cout << "--------------------------------" << endl;
    ICalculatorFactory* calcFactory = new BasicCalcFactory();
    calculator = calcFactory->createCalculator();
    is_new = false;
    DisplayCalculatorUI();
  } else {
    cout << "Enter next calculation:" << endl;
  }

  string userExpression;
  cin >> userExpression;
  calculator->SetExpression(userExpression);
  calculator->CalculateResult();
  double answer = calculator->GetResult();
  Display::DisplayValue(userExpression + "=" + std::to_string(answer));

  cout << "Press M for Menu" << endl;
  string user_menu_input;
  cin >> user_menu_input;
  int menu_option = HandleMenu(user_menu_input);
  if (menu_option == -1) return 0;  // exit app
  if (menu_option == 3) ResetGlobals();

  if (is_save) {
    calculator->SaveCalculation();
    is_save = false;
  }
  if (is_retreive) {
    string to_display =
        retrieve_id == -1
            ? calculator->GetLastCalculation(calculator->GetFileLocation())
            : calculator->GetCalculation(retrieve_id,
                                         calculator->GetFileLocation());
    Display::DisplayValue(to_display);
    is_retreive = false;
  }
  if (is_view_history)
  {
    calculator->ViewAllCalcs();
    is_view_history = false;
  }
  return recursiveImplementation(calculator);
}

void ResetGlobals() {
  is_new = true;
  is_retreive = false;
  retrieve_id = -1;
  is_save = false;
  is_view_history = false;
}