#include "stdafx.h"
#include "CutString.h"


CutString::CutString() {
}


CutString::~CutString() {
}

vector<string> CutString::ReadLineToVector(string s) {
	vector<string> v;
	string ss;
	int i = 0;
	bool instring = false;
	while (i < s.size()) {
		if (s[i] == '\"')
			instring = !instring;
		else
			ss += s[i];
		++i;
		if ((ss.length()>0) && (ss[ss.length() - 1] == ',') && !instring) {
			ss = ss.substr(0, ss.length() - 1);
			boost::trim(ss);
			v.push_back(ss);
			ss = "";
		}
	}
	boost::trim(ss);
	v.push_back(ss);
	return v;
}
