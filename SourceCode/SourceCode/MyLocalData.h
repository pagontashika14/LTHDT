#pragma once
#include "sqlite3.h"
#include "Constant.h"
#include <boost\algorithm\string.hpp>

using namespace std;
class MyLocalData {
public:
	MyLocalData();
	~MyLocalData();
	void Close();
	bool InsertOneRecord(string sbd, int nvso, string nv, double d);
	void InsertOneRecordToQuery(string sbd, int nvso, string nv, double d);
	bool Query();
	string QuerySQL;
private:
	sqlite3 *dbfile;
	bool isOpenDB = false;
	bool connect();
};

