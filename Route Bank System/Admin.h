#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>
#include <string>
#include"Employee.h"
using namespace std;

class Admin :public Employee {
public:
	Admin() {}
	Admin(string nationalID, string name, string password, string gender, double salary)
		:Employee(nationalID, name, password, gender, salary) {	}

};

#endif // ADMIN_H
