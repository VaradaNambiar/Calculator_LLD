#pragma once
#include <string>

using namespace std;

class Persistence
{
private:
	string path ;
 int highest_id =0;

public:
         int WriteTo(const string file_path, const string expression);
  int ReadCalc(int id, const string file_path, string& expression);
       void SetPath(string value);
  int GetHighestId() const;
       string GetPath() const;
  void ViewHistory() const;
};

