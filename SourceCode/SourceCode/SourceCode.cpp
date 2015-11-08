// SourceCode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "FileStudent.h"
#include "Student.h"
#include <iostream>
#include "MyLocalData.h"
#include <math.h>

using namespace std;
int main() {
	FileStudent file;
	MyLocalData db;
	for (int i = 1; i < STUDENT_BEGIN; i++) {
		file.GetLine();
	}
	for (int i = 0; i < STUDENT_COUNT; i++) {
		Student s = file.GetLineToStudent();
		for each (string nv in s.Aspirations()) {
			double score = s.ExamScore(nv) + s.PriorityScore();
			score = roundf(score * 100) / 100;
			bool status = db.InsertOneRecord(s.Identity(), s.NumberOfAspirations(nv), s.DepartmentOfAspiration(nv), score);

			cout << i + 1 << " ";
			cout << "SBD: " << s.Identity() << " ";
			//cout << "Name: " << s.Name() << " ";
			//cout << "NVSO: " << s.NumberOfAspirations(nv) << " ";
			cout << "To: " << s.DepartmentOfAspiration(nv) << " ";
			//cout << "Score: " << s.ExamScore(nv) << " + " << s.PriorityScore();
			if (status) {
				cout << "Success.";
			} else {
				cout << "Fail.";
			}
			cout << endl;
		}
	}
	db.Close();
	system("pause");
	return 0;
}

