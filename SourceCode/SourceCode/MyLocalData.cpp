#include "stdafx.h"
#include "MyLocalData.h"


MyLocalData::MyLocalData() {
	QuerySQL = "";
	if (connect()) {
		sqlite3_exec(dbfile, "drop table nvxt;", NULL, NULL, NULL);
		sqlite3_exec(dbfile, "create table nvxt(sbd varchar(9), nvso int, manv varchar(4), diemxt double precision);", NULL, NULL, NULL);
	}
	else {
		throw "Can't open database.";
	}
}


MyLocalData::~MyLocalData() {
}

void MyLocalData::Close() {
	if (isOpenDB == true) {
		sqlite3_close(dbfile);
	}
}

bool MyLocalData::InsertOneRecord(string sbd, int nvso, string nv, double d) {
	char sql[500];
	snprintf(sql, 500, "insert into nvxt values ('%s',%d,'%s',%f);", sbd.c_str(), nvso, nv.c_str(), d);
	return sqlite3_exec(dbfile, sql, NULL, NULL, NULL) == SQLITE_OK;
}

void MyLocalData::InsertOneRecordToQuery(string sbd, int nvso, string nv, double d) {
	char sql[500];
	snprintf(sql, 500, "insert into nvxt values('%s',%d,'%s',%f);", sbd.c_str(), nvso, nv.c_str(), d);
	QuerySQL += sql;
}

bool MyLocalData::Query() {
	return sqlite3_exec(dbfile, QuerySQL.c_str(), NULL, NULL, NULL) == SQLITE_OK;
}

bool MyLocalData::connect() {
	if (sqlite3_open(DATABASE_NAME, &dbfile) == SQLITE_OK) {
		isOpenDB = true;
		return true;
	}
	return false;
}
