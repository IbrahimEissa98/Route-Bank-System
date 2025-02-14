#ifndef PARSER_H
#define PARSER_H

//#include <vector>
//#include "GlobalData.h"
//#include <fstream>
//#include <iostream>
#include <string>
#include <sstream>
//#include "Client.h"
#include "Admin.h"
//using namespace std;


class Parser
{
public:
	static vector<string> splitClient(string line) {
		vector<string> v;
		stringstream s(line);
		string part;
		while (getline(s, part, '|')) {
			v.push_back(part);
		}
		return v;
	}

	static vector<string> splitEmployee(string line) {
		vector<string> v;
		stringstream s(line);
		string part;
		while (getline(s, part, '|')) {
			v.push_back(part);
		}
		return v;
	}

	static Client ParseToClient(string line) {
		vector<string> v = splitClient(line);
		Client c (v[0], v[1], v[2], v[3], v[4], v[5], v[6], v[7], stod(v[8]));
		return c;
	}

	static Employee ParseToEmployee(string line) {
		vector<string> v = splitEmployee(line);
		Employee e(v[0], v[1], v[2], v[3], v[4], v[5], v[6],
			GlobalMethods::convertDate(v[7]), stod(v[8]));
		return e;
	}

	static Admin ParseToAdmin(string line) {
		vector<string> v = splitEmployee(line);
		Admin a(v[0], v[1], v[2], v[3], v[4], v[5], v[6],
			GlobalMethods::convertDate(v[7]), stod(v[8]));
		//systemAdmin.push_back(a);
		return a;
	}


};

#endif // PARSER_H
