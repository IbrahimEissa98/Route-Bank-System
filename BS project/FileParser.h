#pragma once
#include <fstream>
#include "Admin.h"

class FileParser
{
public:
	static vector<string> split(string line) {
		vector<string> v;
		stringstream s(line);
		string part;
		while (getline(s, part, '|')) {
			v.push_back(part);
		}
		return v;
	}

	static Client ParseToClient(string line) {
		vector<string> v = split(line);
		Client c (v[0], v[1], v[2], v[3], v[4], v[5], v[6], v[7], stod(v[8]));
		return c;
	}

	static Employee ParseToEmployee(string line) {
		vector<string> v = split(line);
		Employee e(v[0], v[1], v[2], v[3], v[4], v[5], v[6],
			convertDate(v[7]), stod(v[8]));
		return e;
	}

	static AccountActivity ParseToAccountActivity(string line) {
		vector<string> v = split(line);
		AccountActivity aa;
		aa.setId(v[0]);
		for (int i = 1; i < v.size(); i++) {
			aa.addTransaction(v[i]);
		}
		return aa;
	}

};

