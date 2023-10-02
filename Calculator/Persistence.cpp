#include "Persistence.h"

#include <fstream>
#include <iostream>

#include "Display.h"

using namespace std;

// FILE STRUCTURE SAVED INTO
// file heading
// 1:
// 2:

int WriteLine(string line, string file);


int Persistence::WriteTo(const string file_path, const string expression) {
  SetPath(file_path);

  if (highest_id==0)
  {
    string header = "SL NO. : Expression";
    WriteLine(header, file_path);
  }

  ++highest_id;
  string text_to_write = std::to_string(highest_id) + ": " + expression;
  return WriteLine(text_to_write, file_path);
}

int Persistence::ReadCalc(int id, const string file_path, string& expression) {
  if (file_path.empty()) {
    return 1;
  }

  SetPath(file_path);
	string line;
  ifstream textFile(file_path);
  // skip previous lines
  for (int line_id = 0; line_id < id; line_id++) getline(textFile, line);
  getline(textFile, expression);
  return 0;
}

void Persistence::SetPath(string value)
{ path = value; }

int Persistence::GetHighestId() const{ return highest_id; }

string Persistence::GetPath() const
{ return path; }

void Persistence::ViewHistory() const {
  if (path.empty()) {
    cout << "File does not exist" << endl;
    return;
  }

	ifstream file(path);
  int id = GetHighestId();
        string line;
        for (int line_id = 0; line_id <= id; line_id++) {
    getline(file, line);
    Display::DisplayValue(line);
        }


}


int WriteLine(string line, string file)
{
  ofstream textFile(file, std::ios_base::app);
  if (textFile.is_open())
  {
    textFile << line
             << "\n ";
    textFile.close();
    return 0;
  } else {
    cout << "Unable to open file" << endl;
    return -1;
  }
}
