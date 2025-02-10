#ifndef ADMIN_H
#define ADMIN_H

#include"Employee.h"


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

	~Admin(){}
};

#endif // ADMIN_H
