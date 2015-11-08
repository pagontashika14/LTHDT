#include "stdafx.h"
#include "Student.h"


Student::Student()
{
	priorityDistrict["KV1"] = 1.5;
	priorityDistrict["KV2-NT"] = 1;
	priorityDistrict["KV2"] = 0.5;
	priorityDistrict["KV3"] = 0;

	priorityEthnic["NDT1"] = 2;
	priorityEthnic["NDT2"] = 1;
	priorityEthnic["Khong"] = 0;

	numOfAspiration["NV1"] = 1;
	numOfAspiration["NV2"] = 2;
	numOfAspiration["NV3"] = 3;
	numOfAspiration["NV4"] = 4;
}


Student::~Student()
{
}

void Student::UpdateProfile(map<string,string> p) {
	profiles = p;
}

void Student::UpdateSubjectScore(map<string, double> s) {
	subjectScores = s;
}

void Student::UpdateAspiration(string nv, vector<string> s) {
	aspiration a;
	a.department = s[0];
	a.combination = CutString::ReadLineToVector(s[1]);
	aspirations[nv] = a;
}

double Student::ExamScore(string nv) {
	double flag = stod(aspirations[nv].combination[3]);
	double sub1 = subjectScores[aspirations[nv].combination[0]];
	double sub2 = subjectScores[aspirations[nv].combination[1]];
	double sub3 = subjectScores[aspirations[nv].combination[2]];
	return (sub1*(flag + 1)+sub2+sub3)/(3 + flag);
}

double Student::PriorityScore() {
	double score = 0;
	if (profiles[PRIORITY] == "UT") score += 1;
	score += (priorityDistrict[profiles[DISTRICT]] + priorityEthnic[profiles[ETHNIC]]) / 3;
	return score;
}

string Student::Identity() {
	return profiles[IDENTITY];
}

string Student::Name() {
	return profiles[NAME];
}

string Student::DepartmentOfAspiration(string nv) {
	return aspirations[nv].department;
}

int Student::NumberOfAspirations(string nv) {
	return numOfAspiration[nv];
}

vector<string> Student::Aspirations() {
	vector<string> v;
	for(auto& item : aspirations) {
		v.push_back(item.first);
	}
	return v;
}

