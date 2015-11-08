#pragma once
#include <map>
#include <fstream>
#include "Constant.h"
#include "CutString.h"
#include "Student.h"

using namespace std;
class FileStudent {
public:
	FileStudent();
	~FileStudent();

	string GetLine();
	Student GetLineToStudent();
private:
	fstream StudentProfile;
	fstream StudentAspiration;
	vector<string> key;

	map<string, string> StudentVectorToMap(vector<string> v);
};

