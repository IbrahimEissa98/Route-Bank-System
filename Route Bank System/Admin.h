#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>
#include <string>
#include"Employee.h"
using namespace std;

class Admin :public Employee {
public:
	Admin() {}
	Admin(string nationalID, string name, string password,
		string gender, string phone, string email, double salary)
		:Employee(nationalID, name, password, gender, phone, email, salary) {	}
	Admin(string nationalID, string name, string password,
		string gender, string phone, double salary)
		:Employee(nationalID, name, password, gender, phone, salary) {
	}
};

#endif // ADMIN_H
