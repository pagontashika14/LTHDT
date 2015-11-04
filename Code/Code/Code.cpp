// Code.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "sqlite3.h"
#include "boost\algorithm\string.hpp"
#include <iostream>
#include "Constant.h"
#include "FileStudent.h"

using namespace std;
int main()
{
	FileStudent file;
	for (int i = 1;i <= NumOfStudent;i++) {
		cout << i << ".  ";
		file.insertOneStudentToDatabase();
	}
	file.disconnectDatabase();
	cout << endl << ">>>>>>>> End <<<<<<<<" << endl;
	system("pause");
    return 0;
}

