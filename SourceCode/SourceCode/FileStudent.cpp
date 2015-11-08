#include "stdafx.h"
#include "FileStudent.h"
#include <iostream>

FileStudent::FileStudent() {
	StudentProfile.open(PROFILE_STUDENT, ios::in);
	StudentAspiration.open(ASPIRATIONS_STUDENT, ios::in);
	if (!(StudentProfile&&StudentAspiration)) throw new exception("Can't open file csv");
	key = CutString::ReadLineToVector(GetLine());
}

FileStudent::~FileStudent() {
}

string FileStudent::GetLine() {
	string s = "";
	string ss;
	char ctemp[500];
	StudentProfile.getline(ctemp, 500);
	s += ctemp;
	StudentAspiration.getline(ctemp, 500);
	ss = ctemp;
	int i = 0;
	while (ss[i] != ',') {
		ss = ss.substr(1, ss.length() - 1);
	}
	s += ss;
	return s;
}

Student FileStudent::GetLineToStudent() {
	Student student;
	vector<string> temp = CutString::ReadLineToVector(GetLine());
	map<string, string> hs = StudentVectorToMap(temp); // D?ng thô c?a Student (harshStudent)
	// Profile
	map<string, string> pro;
	vector<string> profile = PROFILES;
	for each (string item in profile) {
		pro[item] = hs[item];
	}
	student.UpdateProfile(pro);
	//Subject
	map<string, double> sub;
	vector<string> subject = SUBJECTS;
	for each (string item in subject) {
		if (hs[item] != "NA") {
			sub[item] = stod(hs[item]);
		}
	}
	student.UpdateSubjectScore(sub);
	//Aspiration
	vector<string> aspirations = ASPIRATIONS;
	for each (string item in aspirations) {
		string department = item + ".N";
		string combination = item + ".TH";
		if (hs[department] == "NA") continue;
		vector<string> a;
		a.push_back(hs[department]);
		a.push_back(hs[combination]);
		student.UpdateAspiration(item, a);
	}
	return student;
}

map<string, string> FileStudent::StudentVectorToMap(vector<string> v) {
	map<string, string> student;
	for (int i = 0; i < v.size(); i++) {
		student[key[i]] = v[i];
	}
	return student;
}
