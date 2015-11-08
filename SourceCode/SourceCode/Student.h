#pragma once
#include <boost\algorithm\string.hpp>
#include <map>
#include <vector>
#include "CutString.h"
#include "Constant.h"

using namespace std;
class Student {
public:
	Student();
	~Student();
	void UpdateProfile(map<string,string> p);
	void UpdateSubjectScore(map<string, double> s);
	void UpdateAspiration(string nv,vector<string> s);
	double ExamScore(string nv);
	double PriorityScore();
	string Identity();
	string Name();
	string DepartmentOfAspiration(string nv);
	int NumberOfAspirations(string nv);
	vector<string> Aspirations();
private:
	map<string, string> profiles;
	map<string, double> subjectScores;
	struct aspiration {
	public:
		string department;
		vector<string> combination;
	};
	map<string,aspiration> aspirations;
	map<string, double>priorityDistrict;
	map<string, double>priorityEthnic;
	map<string, int>numOfAspiration;
};

