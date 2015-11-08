#pragma once
#include <boost\algorithm\string.hpp>
#include <vector>

using namespace std;
class CutString {
public:
	CutString();
	~CutString();

	static vector<string> ReadLineToVector(string s);
};

