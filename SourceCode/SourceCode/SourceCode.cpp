// SourceCode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "sqlite3.h"

int main()
{
	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;

	rc = sqlite3_open("8.db", &db);

	if (rc) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		exit(0);
	}
	else {
		fprintf(stderr, "Opened database successfully\n");
	}
	sqlite3_close(db);
	system("pause");
    return 0;
}

